#include <stdio.h>
#include <pthread.h>
#include "thread_utils.h"

int main() {
    const int num_threads = 4;
    pthread_t threads[num_threads];

    struct ThreadArgs args[] = {
            {"A", "Str1", 3},
            {"B", "Str2", 2},
            {"C", "Str3", 4},
            {"D", "Str4", 5}
    };

    create_threads(threads, args, num_threads);

    wait_for_threads(threads, num_threads);

    return 0;
}
