#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#define NUM_THREADS 4

void *work(void *args) {
    int *thrdID = (int *)args;
    printf("Hello from thread #%d\n", *thrdID);
    pthread_exit(NULL);
}

int main() {

    pthread_t threadID[4];
    int id = 1;
    pthread_create(&threadID[0], NULL, work, (void *)&id);

    id++;
    pthread_create(&threadID[1], NULL, work, (void *)&id);

    id++;
    pthread_create(&threadID[2], NULL, work, (void *)&id);

    id++;
    pthread_create(&threadID[3], NULL, work, (void *)&id);


    pthread_join(threadID[0], NULL);
    pthread_join(threadID[1], NULL);
    pthread_join(threadID[2], NULL);
    pthread_join(threadID[3], NULL);


    return EXIT_SUCCESS;
}
