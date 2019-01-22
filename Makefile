bin=socks5
cc=g++

$(bin):socks5.cc epoll.cc
	$(cc) -o $@ $^ -std=c++11 

.PHONY:clean
clean:
	rm -f $(bin) 
