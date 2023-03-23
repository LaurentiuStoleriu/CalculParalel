#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#define NUM_THREADS 2

void *work(void *args) 
{
    int myThrdID = (int)args;

    printf("Hello from thread #%d\n", myThrdID);
}

int main() 
{
    pthread_t threadID[NUM_THREADS];

    int myID = 1;
    pthread_create(&threadID[0], NULL, work, (void *)myID);
    myID++;
    pthread_create(&threadID[1], NULL, work, (void *)myID);

    pthread_join(threadID[0], NULL);
    pthread_join(threadID[1], NULL);

    return EXIT_SUCCESS;
}
