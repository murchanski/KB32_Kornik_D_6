#ifndef THREAD_UTILS_H
#define THREAD_UTILS_H

struct ThreadArgs {
    char *name;
    char *str;
    int num;
};

void *thread_function(void *arg);
void create_threads(pthread_t *threads, struct ThreadArgs *args, int num_threads);
void wait_for_threads(pthread_t *threads, int num_threads);

#endif // THREAD_UTILS_H
