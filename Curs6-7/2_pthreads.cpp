#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#define NUM_THREADS 4

void *work(void *args) {
    printf("Hello\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t threadID;
    pthread_create(&threadID, NULL, work, NULL);

    //pthread_join(threadID, NULL);
    for(int i=0; i< 1000000; i++)
    {
        int j = i;
    }
    return EXIT_SUCCESS;
}
