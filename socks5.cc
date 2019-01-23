#include"socks5.h"

//0----表示继续等待
//1----表示成功
//-1---表示错误需要退出
int Socks5Server::AuthHandler(int fd)
{
	char buf[260];
	int len = recv(fd,buf,260,MSG_PEEK);
	if(len <= 0)
	{
		return -1;
	}
	else if(len < 3)
	{
		return 0;
	}
	else
	{
		recv(fd,buf,len,0);
		if(buf[0] != 0x05)
		{ 
			ErrorLog("not soks5");
			return -1;
		}
		return 1;
	}
}

//客户端向代理服务器请求信息
//成功返回serverfd
//失败返回-1
//没到返回-2
int Socks5Server::EstablishmentHandle(int fd)
{
	char buf[256];
	char ip[4];
	char port[2];
	int len = recv(fd,buf,256,MSG_PEEK);
	//最小位10个字节
	if(len <= 0)
	{
		return -1;
	}
	else if(len < 10)
	{
		return -2;   //文件描述符也有可能是0所以返回-2
	}
	else if(len >= 10)
	{
		recv(fd,buf,4,0);
		if(buf[3] == 0x01)
		{
			//ipv4            
			recv(fd,ip,4,0);
			recv(fd,port,2,0);

		}
		else if(buf[3] == 0x03)
		{
			//域名
			char len = 0;
			recv(fd,&len,1,0);
			recv(fd,buf,len,0);   //这一步看不太懂
			buf[len] = '\0';

			recv(fd,port,2,0);
			TraceLog("Address:%s",buf);
			TraceLog("port:%d",port);
			//和前面的分隔开
			struct  hostent* DNS = gethostbyname(buf);
			memcpy(ip, DNS->h_addr, DNS->h_length);


		}
		else if(buf[3] == 0x04)
		{
			//ipv6
			ErrorLog("not support ipv4");
		}
		else
		{
			ErrorLog("not the type");
			return -1;
		}

		struct sockaddr_in addr;
		memset(&addr, 0, sizeof(struct sockaddr_in));
		addr.sin_family = AF_INET;
		memcpy(&addr.sin_addr.s_addr, ip, 4);
		addr.sin_port = *((uint16_t*)port);

		//和goole服务器简历连接
		int serverfd = socket(AF_INET, SOCK_STREAM, 0);
		if(serverfd < 0)
		{
			ErrorLog("server socket");
			return -1;
		}

		if (connect(serverfd, (struct sockaddr*)&addr, sizeof(addr)) < 0)
		{
			ErrorLog("connect error");
			close(serverfd);
			return -1;
		}

		return serverfd;

	}


}


void Socks5Server::RemoveConnect(int fd)
{
   OPEvent(fd,EPOLLIN,EPOLL_CTL_DEL);
   auto it = _fdConnectMap.find(fd);
   Connect* con = it->second;
    
   if(it != _fdConnectMap.end()) 
   {
      if(--(con->_ref) == 0)
       {
          delete con;
          _fdConnectMap.erase(it);
       }
   }
   else
   {
       assert(false);
   }
}


void Socks5Server::Forwarding(Channel* clientchannel,Channel* serverchannel)
{
     char arr[4096];
     int len = recv(clientchannel->_fd,arr,4096,0);
     TraceLog("recv->%d",len);
     if(len < 0)
     {
       ErrorLog("recv error");
       exit(7);
     }
    if(len == 0)
    {
      TraceLog("port close");
      shutdown(serverchannel->_fd,SHUT_WR);
      RemoveConnect(clientchannel->_fd);
    }
    else
    {           //转发数据
         if(send(serverchannel->_fd,arr,len,0) < 0)
           ErrorLog("send  is error");
    }

}
//处理新的连接请求
void Socks5Server::ConnectEventHandler(int newaccept)
{

	OPEvent(newaccept,EPOLLIN,EPOLL_CTL_ADD);
	SetNonblocking(newaccept);

	Connect* con = new Connect;
	con->_state = AUTH;
	con->_clientchannel._fd = newaccept;
	_fdConnectMap[newaccept] = con;
        cout<<"Connect size = "<<_fdConnectMap.size()<<endl;
        con-> _ref++;

}

//处理读事件
void Socks5Server::ReadEventHandler(int newaccept)
{
	//判断是什么状态
//	map<int, Connect*>::iterator it = _fdConnectMap.find(newaccept);
	auto it = _fdConnectMap.find(newaccept);
	if(it != _fdConnectMap.end())
	{
                 
        	Connect* con = it->second;
		if(con->_state == AUTH)
		{
			char reply[2];
			reply[0] = 0x05;
			int ret = AuthHandler(newaccept);
			if(ret == 1)
			{
				reply[1] = 0x00;  //无需用户进一步确认且可以连接
				con->_state = ESTABLISHMENT;  
			}                 
			else if(ret == 0)
			{
				return;
			}
			else if(ret < 0)
			{
				reply[1] == 0xFF;
				RemoveConnect(newaccept);
				TraceLog("recv the socks5 success");
			}  
                        //代理商对客户端的回复 
			if(send(newaccept,reply,2,0) < 0)
			{
				ErrorLog("reply error");
			}
		}
		else if(con->_state == ESTABLISHMENT)
		{      
                        //建立连接并且，客户端对代理服务器发送请求信息 
			char reply[10];
			reply[0] = 0x05;
			int ret = EstablishmentHandle(newaccept);
                        
			if(ret == -2)
			{
				return;
			}
			if(ret >= 0)
			{       
                                reply[1] = 0x00;
				reply[3] = 0x03;
			}
			if(ret == -1)
			{
				reply[1] = 0x01;   //关闭连接
				RemoveConnect(newaccept);
			}
                         //代理商对客户端发起回复
                        if(send(newaccept,reply,10,0) != 10)
                          {
                               ErrorLog("establishment reply");
                          }

			SetNonblocking(ret);
			OPEvent(ret,EPOLLIN,EPOLL_CTL_ADD);
			con->_serverchannel._fd = ret;
			_fdConnectMap[ret] = con;
			con->_state = FORWARDING;
                       con->_ref++;


		}
		else if(con->_state == FORWARDING)
		{
                   //代理商对goole请求转发
                   //goole对代理商进行回复
                   Channel* clinetchannel = &con->_clientchannel;
                   Channel* serverchannel = &con->_serverchannel;
                   if(newaccept == serverchannel->_fd)
                    {
                      swap(clinetchannel,serverchannel);
                    }
                    
                   Forwarding(clinetchannel,serverchannel);
		}
	}
}

void Socks5Server:: WriteEventHandler(int newaccept)
{
	//TraceLog("write");
}


int main()
{

	Socks5Server server(8888);
	server.Start();
	return 0;
}


