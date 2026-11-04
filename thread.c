#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void* routine1(void *arg)
{
int* n=(int*)arg;
int sum=0;
for(int i=1;i<*n+1;i++)
{
sum+=i;
}
printf("sum of first %d natural nos is:%d\n",*n,sum);
}
void* routine2(void *arg)
{
int* n=(int*)arg;
int sum=0;
int j=1;
for(int i=1;i<*n+1;i++)
{
sum+=j;
j+=2;
}
printf("sum of first %d odd natural nos is:%d\n",*n,sum);
}
void* routine3(void *arg)
{
int* n=(int*)arg;
int sum=0;
int j=2;
for(int i=1;i<*n+1;i++)
{
sum+=j;
j+=2;
}
printf("sum of first %d even natural nos is:%d\n",*n,sum);
}
int main()
{
  pthread_t t1,t2,t3;
  int n=10;
  if(pthread_create(&t1,NULL,&routine1,&n)!=0)
  {
    perror("thread1 failed");
    return 1;
  }
   if(pthread_create(&t2,NULL,&routine2,&n)!=0)
  {
    perror("thread1 failed");
    return 1;
  }
  if(pthread_create(&t3,NULL,&routine3,&n)!=0)
  {
    perror("thread1 failed");
    return 1;
  }
  //this is used for waiting 
  pthread_join(t1,NULL);
  pthread_join(t2,NULL);
  pthread_join(t3,NULL);
  return 0;
}
