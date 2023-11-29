#include "child_thread.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    pthread_t child_threads[NUM_THREADS];
    ChildThreadArgs args[NUM_THREADS] = {
            {"1", "Message1"},
            {"2", "Message2"}
    };

    printf("Enter the number of iterations: ");
    scanf("%d", &num_iterations);
    printf("Enter the minimum random number: ");
    scanf("%d", &min_random_number);
    printf("Enter the maximum random number: ");
    scanf("%d", &max_random_number);
    printf("Enter the target random number: ");
    scanf("%d", &target_random_number);

    srand(time(NULL));

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&child_threads[i], NULL, child_thread_function, &args[i]) != 0) {
            perror("pthread_create");
            exit(1);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(child_threads[i], NULL) != 0) {
            perror("pthread_join");
            exit(1);
        }
    }

    printf("Main Thread. All child threads have completed.\n");

    return 0;
}
