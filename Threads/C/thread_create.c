#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* thread_func(void* arg) {
    printf("Thread %ld running\n", (long)arg);
    return NULL;
}

int main() {
    pthread_t thread;
    if (pthread_create(&thread, NULL, thread_func, (void*)1) != 0) {
        perror("pthread_create failed");
        exit(1);
    }
    pthread_join(thread, NULL);
    printf("Thread joined\n");
    return 0;
}