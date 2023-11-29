#ifndef CHILD_THREAD_H
#define CHILD_THREAD_H

#include <pthread.h>

#define NUM_THREADS 2

typedef struct {
    char *name;
    char *message;
} ChildThreadArgs;

extern int num_iterations;
extern int min_random_number;
extern int max_random_number;
extern int target_random_number;

void *child_thread_function(void *arg);
void set_exit_condition();
int get_exit_condition();

#endif
