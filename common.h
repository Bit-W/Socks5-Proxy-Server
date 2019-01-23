#define __COMMON_H__
#ifdef __COMMON_H__

#include<iostream>
#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdarg.h>
#include<sys/epoll.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<map>
#include<netdb.h>
#include<assert.h>
using namespace std;

#define __TRACE__
#define __DEBUG__

static string GetFileName(const string& path)
{
	char ch='/';
#ifdef _WIN32
	ch='\\';
#endif
	size_t pos = path.rfind(ch);
	if(pos==string::npos)
		return path;
	else
		return path.substr(pos+ 1);
}

inline static void __TraceLog(const char* filename,int line, const char* function, const char*format, ...)
{
#ifdef __TRACE__
	//Êä³öµ÷ÓÃº¯ÊýµÄÐÅÏ¢
	fprintf(stdout,"[TRACE][%s:%d->%s]:",GetFileName(filename).c_str(), line, function);
	//Êä³öÓÃ»§´òµÄtraceÐÅÏ¢
	va_list args;
	va_start(args,format);
	vfprintf(stdout,format, args);
	va_end(args);
	fprintf(stdout,"\n");
#endif
}

inline static void __ErrorLog(const char* filename,int line, const char* function, const char*
								format, ...)
{
#ifdef __DEBUG__
	//Êä³öµ÷ÓÃº¯ÊýµÄÐÅÏ¢
	fprintf(stdout,"[ERROR][%s:%d->%s]:",GetFileName(filename).c_str(), line, function);

	//Êä³öÓÃ»§´òµÄtraceÐÅÏ¢
	va_list args;
	va_start(args,format);
	vfprintf(stdout,format, args);
	va_end(args);

	fprintf(stdout," errmsg:%s, errno:%d\n", strerror(errno), errno);
#endif
}

#define TraceLog(...) \
	__TraceLog(__FILE__,__LINE__,__FUNCTION__, __VA_ARGS__);

#define ErrorLog(...) \
	__ErrorLog(__FILE__,__LINE__,__FUNCTION__, __VA_ARGS__);



#endif
