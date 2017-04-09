#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<stdarg.h>
#define MAXLINE 4096
static void err_doit(int errnoflag,int error,const char *fmt,va_list ap)
{
	char buf[MAXLINE];
vsnprintf(buf,MAXLINE,fmt,ap);
if(errnoflag)
snprintf(buf+strlen(buf),MAXLINE-strlen(buf),":%s",strerror(error));
fflush(stdout);
fputs(buf,stderr);
fflush(NULL);
}
void err_sys(const char *fmt,...)
{
	va_list ap;
	va_start(ap,fmt);
	err_doit(1,errno,fmt,ap);
	va_end(ap);
	exit(1);
}
