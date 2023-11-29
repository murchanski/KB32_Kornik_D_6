#include <stdio.h>
#include <unistd.h>
#include "thread.h"

void *child_thread_function(void *arg) {
    for (int i = 1; i <= ITERATIONS; i++) {
        printf("Child Thread. Iteration: %d\n\n", i);
        sleep(SLEEP_INTERVAL);
    }
    pthread_exit(NULL);
}
