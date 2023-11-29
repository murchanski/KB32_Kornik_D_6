#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "thread.h"

int main() {
    pthread_t child_thread;

    if (pthread_create(&child_thread, NULL, child_thread_function, NULL) != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i <= ITERATIONS; i++) {
        printf("Main Thread. Iteration: %d\n\n", i);
        sleep(SLEEP_INTERVAL);
    }

    if (pthread_join(child_thread, NULL) != 0) {
        perror("pthread_join");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}
