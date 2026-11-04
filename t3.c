#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *print_message(void *arg) {
char *message = (char *)arg;
for (int i = 0; i < 5; i++) {
printf("%s: Iteration %d\n", message, i);
sleep(1);
}
return NULL;
}

int main() {
pthread_t thread1, thread2;
char *message1 = "Thread 1";
char *message2 = "Thread 2";

// Create two threads
if (pthread_create(&thread1, NULL, print_message, (void *)message1) != 0) {
fprintf(stderr, "Error creating thread 1\n");
return 1;
}
if (pthread_create(&thread2, NULL, print_message, (void *)message2) != 0) {
fprintf(stderr, "Error creating thread 2\n");
return 1;
}

// Wait for both threads to complete
pthread_join(thread1, NULL);
pthread_join(thread2, NULL);

printf("Both threads have completed.\n");
return 0;
}
