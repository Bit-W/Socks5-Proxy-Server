#include"socks5.h"
 void Socks5Server::ConnectEventHandler(int newaccept)
{
      TraceLog("Connect");
}
 void Socks5Server::ReadEventHandler(int newaccept)
{
      TraceLog("Read");
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

