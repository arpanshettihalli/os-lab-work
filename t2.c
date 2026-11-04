#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
// Thread function must take and return a void pointer (void*)
void* print_message(void* arg) {
int* thread_id = (int*)arg; // Cast the void pointer to an integer pointer
printf("Hello from Thread %d!\n", *thread_id);
pthread_exit(NULL); // Terminate the thread cleanly
}
int main() {
pthread_t thread1, thread2;
int id1 = 1, id2 = 2;
// Create thread 1
if (pthread_create(&thread1, NULL, print_message, &id1) != 0) {
perror("Failed to create thread 1");
return 1;
}

// Create thread 2
if (pthread_create(&thread2, NULL, print_message, &id2) != 0) {
perror("Failed to create thread 2");
return 1;
}
// Wait for both threads to finish
pthread_join(thread1, NULL);
pthread_join(thread2, NULL);
printf("Both threads have finished executing.\n");
return 0;
}
