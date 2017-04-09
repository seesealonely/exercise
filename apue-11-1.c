#include"apue.h"
pthread_t ntid;
void printids(const char *s)
{
	pid_t pid;
	pthread_t tid;
	pid=getpid();
	tid=pthread_self();
	printf("%s pid %u tid %u (0x%x)\n",s,(unsigned int )pid,(unsigned int )tid,(unsigned int)tid);
}
void *thrn_fn(void *arg)
{
printids("new thread: \n");
	return ((void *)0);
}

int main(void)
{
	int err=pthread_create(&ntid,NULL,thrn_fn,NULL);
	if(err)
	err_quit("can't create thread : %s\n",strerror(err));
	printids("main thread:\n");
	sleep(1);
	exit(0);
}
