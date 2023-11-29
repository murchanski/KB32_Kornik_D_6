#ifndef THREAD_H
#define THREAD_H

#include <pthread.h>

#define ITERATIONS 10
#define SLEEP_INTERVAL 2

void *child_thread_function(void *arg);

#endif