#define __SOCKS5_H__
#ifdef __SOCKS5_H__
#include"epoll.h"

class Socks5Server : public EpollServer
{
	public:
		Socks5Server(int port)
                       :EpollServer(port)
		{}
        int AuthHandler(int fd);
        void RemoveConnect(int fd);
        int EstablishmentHandle(int fd);
        virtual void ConnectEventHandler(int newaccept); 
        virtual void ReadEventHandler(int newaccept);
        virtual void WriteEventHandler(int newaccept);
        //身份认证 
	private:
};
#endif 

