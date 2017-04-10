#ifndef _unp_h
#define _unp_h
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/time.h>
#include<time.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<errno.h>
#include<fcntl.h>
#include<netdb.h>
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/uio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/un.h>
#include<stdarg.h>
#include<syslog.h>

#ifdef HAVE_SYS_SELECT_H
#include<sys/select.h>
#endif

#ifdef HAVE_SYS_SYSCTL_H
#include<sys/sysctl.h>
#endif

#ifdef HAVE_POLL_H
#include<poll.h>
#endif

#ifdef HAVE_SYS_EVENT_H
#include<sys/event.h>
#endif

#ifdef HAVE_STRING_H
#include<string.h>
#endif

#ifdef HAVE_SYS_IOCTL_H
#include<sys/ioctl.h>
#endif

#ifdef HAVE_SYS_FILIO_H
#include<sys/filio.h>
#endif

#ifdef HAVE_SYS_SOCKIO_H
#include<sys/sockio.h>
#endif

#ifdef HAVE_PTHREAD_H
#include<pthread.h>
#endif

#ifdef HAVE_NET_IF_DL_H
#include<net/if_dl.h>
#endif

#ifdef HAVE_NETINET_SCTP_H
#include<netinet/sctp.h>
#endif

#ifdef HAVE_NETINET_SCTP_H
#include<netinet/sctp.h>
#endif

#ifdef _osf_
#undef recv
#undef send
#define recv(a,b,c,d) recvfrom(a,b,c,d,0,0)
#define send(a,b,c,d) sendto(a,b,c,d,0,0)
#endif

#ifdef INADDR_NONE
#define INADDR_NONE 0xffffffff
#endif

#ifndef SHUT_RD
#define SHUT_RD 0
#define SHUT_WR 1
#define SHUT_RDWR 2
#endif

#ifndef INET_ADDRSTRLEN
#define INET_ADDRSTRLEN 16
#endif

#ifndef INET6_ADDRSTRLEN
#define INET6_ADDRSTRLEN 46
#endif

#ifndef HAVE_BZERO
#define bzero(ptr,n)
#endif
#ifndef HAVE_GETHOSTBYNAME2
#define gethostbyname2(host,family)
#endif

struct unp_in_pktinfo
{
	struct in_addr ipi_addr;
	int ipi_ifindex;
};

#ifndef CMSG_LEN
#define CMSG_LEN(size) (sizeof(struct cmsghdr)+(size))
#endif

#ifndef CMSG_SPACE
#define CMSG_SPACE(size) (sizeof(struct cmsghdr)+(size))
#endif

#ifndef SUN_LEN
#define SUN_LEN \
	(sizeof(*(su))-sizeof((su)->sun_path)+strlen((su)->sun_path))
#endif

#ifndef AF_LOCAL
#define AF_LOCAL AF_UNIX
#endif

#ifndef PF_LOCPL
#define PF_LOCPL PF_UNIX
#endif

#ifndef INFTIM
#define INFTIM (-1)
#endif

#ifdef HAVE_POLL_H
#define INFTIM_UNPH
#endif
#endif

#define LISTENQ 1024
#define MAXLINE 4096
#define BUFFSIZE 8192
#define SERV_PORT 9877
#define SERV_PORT_STR "9877"
#define UNIXSTR_PATH "/tmp/unix.str"
#define UNIXDG_PATH "/tmp/unix.dg"

#define SA struct sockaddr

#define HAVE_STRUCT_SOCKADDR_STORAGE
#ifndef HAVE_STRUCT_SOCKADDR_STORAGE

#define _SS_MAXSIZE 128
#define _SS_ALIGNSIZE (sizeof(int64_t))
#ifdef HAVE_SOCKADDR_SA_LEN
#define _SS_PAD1SIZE (_SS_ALIGNSIZE - sizeof(u_char) -sizeof(sa_family_t))
#else
#define _SS_PAD1SIZE (_SS_ALIGNSIZE -sizeof(sa_family_t))
#endif

struct sockaddr_storage
{
	#ifdef HAVE_SOCKADDR_SA_LEN
	u_char ss_len;
	#endif
	sa_family_tss_family;
char _ss_pad1[_SS_PAD1SIZE];
int64_t _ss_align;
	char _ss_pad2[_SS_PAD2SIZE];
};
#endif

#define FILE_MODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)
#define DIR_MODE (FILE_MODE|S_IXUSR|S_IXGRP|S_IXOTH)
typedef void Sigfunc(int);
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#ifndef HAVE_ADDRINFO_STRUCT
//#include "../lib/addrinfo.h"
#endif

#ifndef  HAVE_IF_NAMEINDEX_STRUCT
struct if_nameindex
{
	unsigned int if_index;
char *if_name;
};
#endif
/*
#ifndef HAVE_TIMESPEC_STRUCT
struct timespec
{
	time_t tv_sec;
	long tv_nsec;
};
#endif
*/
int daemon_proc;
static void err_doit(int,int,const char *,va_list);
void err_ret(const char *fmt,...)
{
	va_list ap;
	va_start(ap,fmt);
	err_doit(1,LOG_INFO,fmt,ap);
	va_end(ap);	
	return ;
}

void err_sys(const char *fmt,...)
{
	va_list ap;
	va_start(ap,fmt);
	err_doit(1,LOG_ERR,fmt,ap);
	va_end(ap);
	exit(1);
}

void err_dump(const char *fmt,...)
{
	va_list ap;
	va_start(ap,fmt);
	err_doit(1,LOG_ERR,fmt,ap);
	va_end(ap);
	abort();
	exit(1);
}

void err_msg(const char *fmt,...)
{
	va_list ap;
	va_start(ap,fmt);
	err_doit(0,LOG_INFO,fmt,ap);
	va_end(ap);
	return;
}

void err_quit(const char *fmt,...)
{
	va_list ap;
	va_start(ap,fmt);
	err_doit(0,LOG_ERR,fmt,ap);
	va_end(ap);
	exit(1);
}

static void err_doit(int errnoflag,int level,const char *fmt,va_list ap)
{
	int errno_save=0,n=0;
	char buf[MAXLINE+1];
	#ifdef HAVE_VSNPRINTF
vsnprintf(buf,MAXLINE,fmt,ap);
	#else
	vsprintf(buf,fmt,ap);
#endif
	n=strlen(buf);
	if(errnoflag)
	snprintf(buf+n,MAXLINE-n,":%s",strerror(errno_save));
	strcat(buf,"\n");
	if(daemon_proc)
	{
	syslog(level,buf);
	}
	else
	{
	fflush(stdout);	
	fputs(buf,stderr);
	fflush(stderr);
	}
	return ;
}

int Socket(int family,int type,int protocol)
{
	int n=0;
	if((n==socket(family,type,protocol))<0)
	err_sys("socket error\n");
	return n;
}

void Pthread_mutex_lock(pthread_mutex_t *mptr)
{
	int n=0;
	if((n=pthread_mutex_lock(mptr))==0)
	return ;
	errno=n;
	err_sys("pthread_mutex_lock error\n");
}
