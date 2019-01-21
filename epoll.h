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
        void Start();
        void EventLoop();

protected:
   int _port;
   int _listenfd;
   int _eventfd;  //事件描述符
};
#endif
