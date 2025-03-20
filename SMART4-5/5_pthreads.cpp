#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 4

typedef struct ThreadArgs {
	int threadID;
	int *array;
	int size;
} ThreadArgs;


int count = 0;
pthread_mutex_t countLock = PTHREAD_MUTEX_INITIALIZER;

int* createArray(int size, int numai5);
ThreadArgs* createArgs(int id, int *array, int size);
void* numara5Threaded(void *myArgs);

int main() 
{
    int size = 1000000;
    int *array = createArray(size, 1);
    count = 0;
    pthread_t threads[NUM_THREADS];

    for (int i=0; i<NUM_THREADS; i++){
        ThreadArgs *args = createArgs(i, array, size);
        pthread_create(&threads[i], NULL, numara5Threaded, (void *)args);
    }

    for (int i=0; i<NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }

    printf("Avem %d elemente egale cu 5 in array\n", count);
    free(array);
    return EXIT_SUCCESS;
}


int* createArray(int size, int numai5) {
    srand(time(NULL));
    int *array = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        int r = rand();
        if (numai5) {
            array[i] = 5;
        }
        else {
            array[i] = (r % 10) + 1;
        }
    }
    return array;
}

ThreadArgs* createArgs(int id, int *array, int size){
    ThreadArgs *myArgs = (ThreadArgs *)malloc(sizeof(ThreadArgs));
    myArgs->threadID = id;
    myArgs->array = array;
    myArgs->size = size;
    return myArgs;
}

void* numara5Threaded(void *myArgs) {
    ThreadArgs *args = (ThreadArgs *)myArgs;
    int lenPerThread = args->size / NUM_THREADS;
    int start = args->threadID * lenPerThread;
    int *array = args->array;
    for (int i = start; i < (start + lenPerThread); i++) {
        if (5 == array[i]) {
            pthread_mutex_lock(&countLock);
            count++;
            pthread_mutex_unlock(&countLock);
        }
    }
    free(args);
    pthread_exit(NULL);
}


    