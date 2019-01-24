#ifndef __TRANFER_H__
#define __TRANFER_H__

#include"common.h"
#include"epoll.h"

class TranferServer : public EpollServer
{
	public:
		TranferServer(int selfport,const char* socks5ip,int socks5port)
                           :EpollServer(selfport)
		{
                   socks5addr.sin_family = AF_INET;
                   socks5addr.sin_port = htons(socks5port);
                   socks5addr.sin_addr.s_addr = inet_addr(socks5ip);
		}
		virtual void ConnectEventHandler(int newaccept);
		virtual void ReadEventHandler(int newaccept);
	protected:
		struct sockaddr_in socks5addr;
};



#endif
