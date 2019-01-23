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
	memset(&addr, 0, sizeof(addr));
	size_t len = sizeof(addr);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(_port);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);    
	int ret = bind(_listenfd,(struct sockaddr*)&addr,len);
	if(ret < 0)
	{
		ErrorLog("bind socket error");
		exit(1);
	}

	//监听
	if(listen(_listenfd,100000) < 0)
	{
		ErrorLog("listen socket error");
		exit(2);
	}

	TraceLog("epoll sever listen on %d",_port);
	TraceLog("epoll sever listen on %d",_listenfd);
	_eventfd = epoll_create(100000);
	if(_eventfd < 0)
	{
		ErrorLog("epoll create");
		exit(3);
	}
        
	
	//添加事件  epoll_ctl
	OPEvent(_listenfd,EPOLLIN,EPOLL_CTL_ADD);

        //设置非阻塞   
	SetNonblocking(_listenfd);

	//进入事件循环
	EventLoop();
}
void EpollServer::EventLoop()
{
	//事件的监听  epoll_wait()
	//1.判断是否位监听事件，如果是就建立连接
	

        //监听数组
	struct epoll_event evs[100000];
	while(1) 
	{
		int ret = epoll_wait(_eventfd,evs,100000,0);
                if(ret < 0 )
                {
                     ErrorLog("epoll_wait");
                }

		for(int i = 0;i < ret + 1;++i)
		{
                       // cout<<"listen="<<_listenfd<<endl;
                        // cout<<"evs[i]"<<evs[i].data.fd<<endl;
                         
			//请求的新连接
			if(evs[i].data.fd == _listenfd)
			{
				struct sockaddr_in peer;
				socklen_t  len = sizeof(peer);
				int newaccept = accept(_listenfd,(struct sockaddr*)&peer,&len);
				if(newaccept < 0)
				{
					ErrorLog("accept false");
				}
				//添加事件
                                ConnectEventHandler(newaccept);
			}
			else if(evs[i].data.fd & EPOLLIN)
			{    //读事件
				ReadEventHandler(evs[i].data.fd);
			}
			else if(evs[i].data.fd & EPOLLOUT)
			{   //写事件
				WriteEventHandler(evs[i].data.fd);
			}
			else
			{
				//错误事件
			}


		}


	}
}
