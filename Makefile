bin=socks5
cc=g++

.PHONY:all
all:$(bin) to

$(bin):socks5.cc epoll.cc 
	$(cc) -o $@ $^ -std=c++11 

.PHONY:to
to:
	g++ -o tranfer tranfer.cc epoll.cc -std=c++11
.PHONY:clean
clean:
	rm -f $(bin) $(sec) tranfer
