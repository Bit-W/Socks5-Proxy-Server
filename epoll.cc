#include"epoll.h"

void EpollServer::Start()
{
	//TCP编程
	//1.创建socket
	_listenfd = socket(AF_INET,SOCK_STREAM,0);
	if(_listenfd < 0)
	{
		ErrorLog("create socket");
		exit(0);
	}
	//2.绑定地址
	struct sockaddr_in addr;
	size_t len = sizeof(addr);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);    
	int ret = bind(_listenfd,(struct sockaddr*)&addr,len);
	if(ret < 0)
	{
		ErrorLog("bind socket error");
		exit(1);
	}

	//监听
	if(listen(_listenfd,5) < 0)
	{
		ErrorLog("listen socket error");
		exit(2);
	}

        TraceLog("epoll sever listen on %d",_port);
}
void EpollServer::EventLoop()
{




}
