#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#define NUM_THREADS 4

void* work(void *thrdID) {
    int *myID = (int *)thrdID;
    printf("Hello din thread #%d\n", *myID);
    pthread_exit(NULL);
}

int main() {
    pthread_t threadID[NUM_THREADS];
    int ID = 1;
    pthread_create(&threadID[0], NULL, work, (void *)&ID);

    // for(int i=0;i<1000000;i++)
    // {
    //     int j = i;
    // }
    ID++;
    pthread_create(&threadID[1], NULL, work, (void *)&ID);

    pthread_join(threadID[0], NULL);
    pthread_join(threadID[1], NULL);
    
    return EXIT_SUCCESS;
}