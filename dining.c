#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#define n 5
sem_t p[n];

void* philosophers(void* arg)
{
  int *id=(int*)arg;
  int left=*id;
  int right=(*id+1)%n;
  for(int i=0;i<10;i++)
  {
  printf("philosopher %d is thinking\n",*id);
  sleep(1);
  if(*id==n-1)
  {
      sem_wait(&p[right]);
      sem_wait(&p[left]);
    }
    else
    {
      sem_wait(&p[left]);
      sem_wait(&p[right]);
    }
    printf("philosopher %d is eating\n",*id);
    sleep(1);
    sem_post(&p[left]);
    sem_post(&p[right]);
    printf("philosopher %d has finished eating\n",*id);
  }
}
int main()
{
pthread_t t[n];
int id[n];
  for(int i=0;i<n;i++)
  {
    sem_init(&p[i],0,1);
  }
  for(int i=0;i<n;i++)
  {
  id[i]=i;
  pthread_create(&t[i],NULL,&philosophers,&id[i]);
  }
  for(int i=0;i<n;i++)
  {
  pthread_join(t[i],NULL);
  }
  for(int i=0;i<n;i++)
  {
    sem_destroy(&p[i]);
  }
  return 0;
}
    
