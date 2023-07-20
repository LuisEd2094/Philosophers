#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdint.h>


pthread_mutex_t mutex; // The Mutex

void* thread_function(void* arg) {
    // Critical Section
    printf("Thread %d is in the critical section.\n", *(int*)arg);
    for (int i = 0; i < 10; i++)
    {    
        pthread_mutex_lock(&mutex); // Acquire the Mutex
        printf("Thread %d has an i value of %i\n", *(int *) arg, i);
        pthread_mutex_unlock(&mutex); // Release the Mutex
        printf("Released\n");


    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    int thread1_id = 1, thread2_id = 2;
/*
    pthread_mutex_init(&mutex, NULL); // Initialize the Mutex

    // Create two threads
    pthread_create(&thread1, NULL, thread_function, &thread1_id);
    pthread_create(&thread2, NULL, thread_function, &thread2_id);

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&mutex); // Destroy the Mutex*/

    struct timeval tv;

    gettimeofday(&tv,NULL);

    uint64_t time= (tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000);

    printf("%li %li   %li\n", tv.tv_sec, tv.tv_usec, time);

    return 0;
}