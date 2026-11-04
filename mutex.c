#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
int x=0;
pthread_mutex_t mutex;
void* routine(void *arg)
{
for(int i=0;i<1000000;i++)
{	pthread_mutex_lock(&mutex);
pthread_mutex_lock(&mutex);
	x++;
	pthread_mutex_unlock(&mutex);
}
}
int main()
{	pthread_mutex_init(&mutex,NULL);
	pthread_t t[2];
	pthread_create(&t[0],NULL,&routine,NULL);
	pthread_create(&t[1],NULL,&routine,NULL);
	pthread_join(t[0],NULL);
	pthread_join(t[1],NULL);
	pthread_mutex_destroy(&mutex);
	printf("%d",x);
	return 0;
}
