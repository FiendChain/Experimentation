#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

void fibonacci(void *vargs);
void iterator(void *vargs);

int main(int argc, char *argv[]) {
    pthread_t fibonacci_thread;
    pthread_t iterator_thread;
    int total_iterations = 10;
    // create threads
    printf("Creating threads\n");
    pthread_create(&fibonacci_thread, NULL, (void *)fibonacci, (void *)(&total_iterations));
    pthread_create(&iterator_thread, NULL, (void *)iterator, (void *)(&total_iterations));
    // join threads
    pthread_join(fibonacci_thread, NULL);
    pthread_join(iterator_thread, NULL);

    return EXIT_SUCCESS;
}

void fibonacci(void *vargs) {
    int n = *(int *)vargs;
    unsigned long long x = 0, y = 1;
    unsigned long long next;
    for(int i = 0; i < n; i++) {
        printf("fib(%d): %llu\n", i, x);
        next = x + y;
        x = y;
        y = next;
        sleep(2);
    }
}

void iterator(void *vargs) {
    int n = *(int *)vargs;
    for(int i = 0; i < n; i++) {
        printf("iterator: %d\n", i);
        sleep(1);
    }
}

