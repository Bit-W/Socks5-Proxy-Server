epoll.cc: In member function ‘void EpollServer::EventLoop()’:
epoll.cc:74:70: error: invalid conversion from ‘size_t {aka long unsigned int}’ to ‘socklen_t* {aka unsigned int*}’ [-fpermissive]
     int newaccept = accept(evs[i].data.fd,(struct sockaddr*)&peer,len);
                                                                      ^
In file included from common.h:11:0,
                 from epoll.h:3,
                 from epoll.cc:1:
/usr/include/sys/socket.h:244:12: error:   initializing argument 3 of ‘int accept(int, sockaddr*, socklen_t*)’ [-fpermissive]
 extern int accept (int __fd, __SOCKADDR_ARG __addr,
            ^
epoll.cc:80:9: error: request for member ‘data’ in ‘evs’, which is of non-class type ‘epoll_event [100000]’
     evs.data.fd = newaccept;
         ^
epoll.cc:81:9: error: request for member ‘evnets’ in ‘evs’, which is of non-class type ‘epoll_event [100000]’
     evs.evnets = EPOLLIN;
         ^
epoll.cc:82:63: error: cannot convert ‘sockaddr_in*’ to ‘epoll_event*’ for argument ‘4’ to ‘int epoll_ctl(int, int, int, epoll_event*)’
     int ret = epoll_ctl(_eventfd,EPOLL_CTL_ADD,newaccept,&peer);
                                                               ^
make: *** [socks5] Error 1
