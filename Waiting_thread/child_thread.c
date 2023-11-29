#include "child_thread.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int num_iterations;
int min_random_number;
int max_random_number;
int target_random_number;
int exit_condition = 0;
pthread_mutex_t exit_condition_mutex = PTHREAD_MUTEX_INITIALIZER;

void set_exit_condition() {
    pthread_mutex_lock(&exit_condition_mutex);
    exit_condition = 1;
    pthread_mutex_unlock(&exit_condition_mutex);
}

int get_exit_condition() {
    int result;
    pthread_mutex_lock(&exit_condition_mutex);
    result = exit_condition;
    pthread_mutex_unlock(&exit_condition_mutex);
    return result;
}

void *child_thread_function(void *arg) {
    ChildThreadArgs *args = (ChildThreadArgs *)arg;
    for (int i = 1; i <= num_iterations; i++) {
        if (get_exit_condition()) {
            printf("Child Thread %s. Exiting due to exit condition.\n", args->name);
            pthread_exit(NULL);
        }

        printf("Child Thread %s. %s %d\n", args->name, args->message, i);

        int random_number = min_random_number + rand() % (max_random_number - min_random_number + 1);
        printf("Child Thread %s. Random Number: %d\n", args->name, random_number);

        if (random_number == target_random_number) {
            printf("Child Thread %s. Received %d, setting exit condition.\n", args->name, target_random_number);
            set_exit_condition();
        }
        sleep(1);
    }
    pthread_exit(NULL);
}
