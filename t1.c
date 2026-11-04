#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
void* func(void* arg)
{
pthread_detach(pthread_self());// detach the current thread from the calling thread
printf("Inside the thread\n");
pthread_exit(NULL); // exit the current thread
}
void fun()
{
pthread_t ptid;
pthread_create(&ptid, NULL, &func, NULL); // Creating a new thread
printf("This line may be printed before thread terminates\n");
if(pthread_equal(ptid, pthread_self())) // Compare the two threads created
printf("Threads are equal\n");
else
printf("Threads are not equal\n");
pthread_join(ptid, NULL); // Waiting for the created thread to terminate

printf("This line will be printed after thread ends\n");
pthread_exit(NULL);
}
int main()
{
fun();
return 0;
}
