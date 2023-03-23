#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void *work(void *args) 
{
    printf("Hello\n");
}

int main() 
{
    pthread_t threadID;
    pthread_create(&threadID, NULL, work, NULL);

    pthread_join(threadID, NULL);

    return EXIT_SUCCESS;
}
