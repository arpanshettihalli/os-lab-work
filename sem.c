#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
int x=0;
sem_t semaphore;
void* routine(void *arg)
{
for(int i=0;i<1000000;i++)
{	sem_wait(&semaphore);
	x++;
	sem_post(&semaphore);
}
}
int main()
{	sem_init(&semaphore,0,2);
	pthread_t t[2];
	pthread_create(&t[0],NULL,&routine,NULL);
	pthread_create(&t[1],NULL,&routine,NULL);
	pthread_join(t[0],NULL);
	pthread_join(t[1],NULL);
	sem_post(&semaphore);
	printf("%d",x);
	return 0;
}
