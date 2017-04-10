#include"apue.h"
struct foo
{
	int f_count;
	pthread_mutex_t f_lock;
};
struct foo *foo_alloc(void)
{
	struct foo *fp;
	if(fp=malloc(sizeof(struct foo)))
	{
		fp->f_count=1;
		if(pthead_mutex_init(&fp->f_lock,NULL))
		{
			free(fp);
			return NULL;
		}
	}
	return fp;
}

void foo_hold(struct foo *fp)
{
	pthread_mutex_lock(&fp->lock);
	fp->f_count++;
	pthread_mutex_unlock(&fp->lock);
}

void foo_rele(struct foo *fp)
{
	pthread_mutex_lock(&fp->f_lock);
	if(--fp->f_count==0)
	{
	pthread_mutex_unlock(&fp->f_lock);
	pthread_mutex_destroy(&fp->f_lock);
	free(fp);
	}
	else pthread_mutex_unlock(&fp->f_lock);
}
