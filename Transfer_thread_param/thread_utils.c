#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "thread_utils.h"

void *thread_function(void *arg) {
    struct ThreadArgs *args = (struct ThreadArgs *)arg;
    for (int i = 1; i <= args->num; i++) {
        printf("Thread %s. %s %d\n", args->name, args->str, i);
    }
    pthread_exit(NULL);
}

void create_threads(pthread_t *threads, struct ThreadArgs *args, int num_threads) {
    for (int i = 0; i < num_threads; i++) {
        if (pthread_create(&threads[i], NULL, thread_function, &args[i]) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }
}

void wait_for_threads(pthread_t *threads, int num_threads) {
    for (int i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
    }
}
