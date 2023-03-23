#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void *work(void *args) 
{
    int myThrdID = (int)args;

    printf("Hello from thread #%d\n", myThrdID);
}

int main() 
{
    pthread_t threadID;

    int myID = 1;
    pthread_create(&threadID, NULL, work, (void *)myID);

    pthread_join(threadID, NULL);

    return EXIT_SUCCESS;
}
