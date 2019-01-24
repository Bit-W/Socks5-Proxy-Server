#ifndef __EPOLL_H__
#define __EPOLL_H__
#include"common.h"
#include"encry.h"
//信号处理忽略信号
class IgnoreSigPipe
{
public:
	IgnoreSigPipe()
	{
		::signal(SIGPIPE, SIG_IGN);
	}
};

static IgnoreSigPipe initPIPE_IGN;

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
			ev.data.fd = fd;
			ev.events = events;
			int ret = epoll_ctl(_eventfd,op,fd,&ev);
			if(ret < 0)
			{
				ErrorLog("epoll_ctl");
				exit(4);
			}
		}
                //非阻塞设置
		void SetNonblocking(int sfd)
		{

			int flags = fcntl (sfd, F_GETFL, 0);
			if (flags == -1)
				ErrorLog("SetNonblocking:F_GETFL");

			flags |= O_NONBLOCK;
			int s = fcntl (sfd, F_SETFL, flags);
			if (s == -1)
				ErrorLog("SetNonblocking:F_SETFL");

		}

		//身认证   建立连接   转发
		enum Socks5State
		{
			AUTH,				// 身份认证
			ESTABLISHMENT,		// 建立连接
			FORWARDING,			// 转发
		};

		//建立结构
		struct Channel
		{
			int _fd;   //描述符
			string _buff;  //写缓冲

			Channel()
				:_fd(-1)
			{             
			}
		};

		struct Connect
		{
			Socks5State _state;
			Channel _clientchannel;   //管道
			Channel _serverchannel;   //管道
			int _ref;
			Connect()
				:_state(AUTH)
				 ,_ref(0)
			{
			}
		};
 
               void SendInLoop(int fd,const char* arr,int len);
               void RemoveConnect(int fd);
               void Forwarding(Channel* clientchannel,Channel* serverchannel,bool sendencry,bool recvencry);
		//多态实现的虚函数（实现复用）可以减少代码的冗余，让代码都在子类中实现
		virtual void ConnectEventHandler(int newaccept) = 0;
		virtual void ReadEventHandler(int newaccept) = 0;
		virtual void WriteEventHandler(int newaccept);
		void Start();
		void EventLoop();

	protected:
		int _port;
		int _listenfd;
		int _eventfd;  //事件描述符
		map<int,Connect*> _fdConnectMap;
};
#endif
