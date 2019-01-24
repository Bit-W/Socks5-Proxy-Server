#include"tranfer.h"

void TranferServer::ConnectEventHandler(int newaccept)
{
	int serverfd = socket(AF_INET, SOCK_STREAM, 0);
	if (serverfd == -1)
	{
		ErrorLog("socket");
		return;
	}
	//tranfer和socks5建立连接  
	int len = sizeof(socks5addr);
	if(connect(serverfd,(struct sockaddr*)&socks5addr,len) < 0)
	{
		ErrorLog("connect");
		return;
	}
	//客户端和tranfer建立连接
	SetNonblocking(newaccept);
	OPEvent(newaccept,EPOLLIN,EPOLL_CTL_ADD);
	Connect* con = new Connect;
	con->_clientchannel._fd = newaccept;
	con->_state = FORWARDING;
	con->_ref++;
	_fdConnectMap[newaccept] = con;

	//建立tranfer和socks5连接
	SetNonblocking(serverfd);
	OPEvent(serverfd,EPOLLIN,EPOLL_CTL_ADD);
	con->_serverchannel._fd = serverfd;
	con->_ref++;
	_fdConnectMap[serverfd] = con;
}
void TranferServer::ReadEventHandler(int newaccept)
{
	auto it = _fdConnectMap.find(newaccept);

		Connect* con = it->second;
		Channel* clientchannel = &con->_clientchannel;
		Channel* serverchannel = &con->_serverchannel;
	if(it != _fdConnectMap.end())
	{
		if(newaccept == con->_serverchannel._fd)
		{
			swap(clientchannel,serverchannel);
		}
		Forwarding(clientchannel,serverchannel);
	}
	else
	{
		assert(false);
	}

}
int main()
{
	TranferServer server(8000,"127.0.0.1",8888);
	server.Start();
	return 0;
}
