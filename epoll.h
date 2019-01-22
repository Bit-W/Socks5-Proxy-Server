#define __EPOLL_H__
#ifdef __EPOLL_H__
#include"common.h"
class EpollServer
{
public:
	EpollServer(int port = 8888)
             :_port(port)
             ,_listenfd(-1)
             ,_eventfd(-1)
	{}

        ~EpollServer()
        {
          if(_listenfd)
             close(_listenfd);
        }
        
        void OPEvent(int fd,int events,int op)
        {
           struct epoll_event ev;
           ev.data.fd = events;
           ev.events = fd;
           int ret = epoll_ctl(_eventfd,op,fd,&ev);
           if(ret < 0)
           {
             ErrorLog("epoll_ctl");
             exit(4);
           }
        }
        void SetNonblocking(int sfd)
        {
		int flags, s;
		flags = fcntl (sfd, F_GETFL, 0);
		if (flags == -1)
			ErrorLog("SetNonblocking:F_GETFL");

		flags |= O_NONBLOCK;
		s = fcntl (sfd, F_SETFL, flags);
		if (s == -1)
			ErrorLog("SetNonblocking:F_SETFL");
             
        }
        virtual void ConnectEventHandler(int newaccept) = 0;
        virtual void ReadEventHandler(int newaccept) = 0;
        virtual void WriteEventHandler(int newaccept) = 0;
        void Start();
        void EventLoop();

protected:
   int _port;
   int _listenfd;
   int _eventfd;  //事件描述符
};
#endif
