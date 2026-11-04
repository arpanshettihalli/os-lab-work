#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
pthread_mutex_t mutex;
int in=0,out=0,count=0;
int buffersize=5;
int buffer[5];
void* producer(void* arg)
{
  
  for(int i=1;i<=10;i++)
  {
  int item=i;
  while(count>=buffersize)
    sleep(0.1);
  pthread_mutex_lock(&mutex);
  buffer[in]=item;
  printf("producer produced:%d\n",i);
  in=(in+1)%buffersize;
  count++;
  pthread_mutex_unlock(&mutex);
  sleep(1);
  }
}
void* consumer(void* arg)
{
  
  for(int i=1;i<=10;i++)
  {
  while(count==0)
    sleep(0.1);
  pthread_mutex_lock(&mutex);
  int t=buffer[out];
  printf("consumer consumed:%d\n",t);
  out=(out+1)%buffersize;
  count--;
  pthread_mutex_unlock(&mutex);
  sleep(1);
  }
}
int main()
{
  pthread_t t1,t2;
  pthread_mutex_init(&mutex,NULL);
  pthread_create(&t1,NULL,&producer,NULL);
   pthread_create(&t2,NULL,&consumer,NULL);
   pthread_join(t1,NULL);
   pthread_join(t2,NULL);
   pthread_mutex_destroy(&mutex);
   return 0;
  }
  
