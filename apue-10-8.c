#include"apue.h"
static  jmp_buf env_alrm;
static void sig_alrm(int signo)
{
longjmp(env_alrm,1);
printf("signo %d\n",signo);
}
int  main(void)
{
	int n;
	char line[MAXLINE];
	if(signal(SIGALRM,sig_alrm)==SIG_ERR)
	err_sys("signal(SIGALRM) error\n");
	if(setjmp(env_alrm)!=0)
	err_quit("read timeout\n");
	alarm(1);
	if((n=read(STDOUT_FILENO,line,MAXLINE))<0)
	err_sys("read error\n");
	alarm(0);
	write(STDOUT_FILENO,line,n);
	exit(0);
}
