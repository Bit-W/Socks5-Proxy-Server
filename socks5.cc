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
		return -2;
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

			recv(fd,port,2,0);
			TraceLog("Address:%s",buf);
			TraceLog("port:%d",port);
			//和前面的分隔开
			buf[len] = '\0';
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
}

//处理新的连接请求
void Socks5Server::ConnectEventHandler(int newaccept)
{
	TraceLog("Connect");

	OPEvent(newaccept,EPOLLIN,EPOLL_CTL_ADD);
	SetNonblocking(newaccept);
	Connect* con = new Connect;
	con->_state = AUTH;
	con->_clientchannel._fd = newaccept;
	_fdConnectMap[newaccept] = con;

}

//处理读事件
void Socks5Server::ReadEventHandler(int newaccept)
{
	TraceLog("Read");
	//判断是什么状态
	auto it = _fdConnectMap.find(newaccept);
	Connect* con = it->second;
	if(it != _fdConnectMap.end())
	{
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
				exit(5);
			}
			else if(ret < 0)
			{
				reply[1] == 0xFF;
				RemoveConnect(newaccept);
				TraceLog("recv the socks5 success");
			}   
			if(send(newaccept,reply,2,0) < 0)
			{
				ErrorLog("reply error");
			}
		}
		else if(con->_state == ESTABLISHMENT)
		{       
			char reply[10];
			reply[0] = 0x05;
			int ret = EstablishmentHandle(newaccept);
			if(ret == -2)
			{
				exit(5);
			}
			if(ret >= 0)
			{       
				reply[2] = 0x00;
				reply[3] = 0x03;
			}
			if(ret == -1)
			{
				reply[1] = 0x01;   //关闭连接
				RemoveConnect(newaccept);
				exit(6);
			}
			SetNonblocking(ret);
			OPEvent(ret,EPOLLIN,EPOLL_CTL_ADD);
			con->_serverchannel._fd = ret;
			_fdConnectMap[ret] = con;
			con->_state = FORWARDING;


		}
		else if(con->_state == FORWARDING)
		{
		}
	}
}

void Socks5Server:: WriteEventHandler(int newaccept)
{
	TraceLog("write");
}


int main()
{

	Socks5Server server(8888);
	server.Start();
	return 0;
}

