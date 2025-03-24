#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_THREADS 4

int globalCount[NUM_THREADS];

struct ThreadArgs {
    int threadID;
    int *array;
    int size;
};
typedef struct ThreadArgs ThreadArgs;

int* createArray(int size, int numai5);
ThreadArgs* createArgs(int id, int *array, int size);
int numara5MasterThread(int *array, int size);
void* numara5Threads(void *myArgs);
double computeTime(struct timespec start, struct timespec end);

struct timespec timeStart, timeEnd;

int main() 
{
    int size = 1000000;
    int *array = createArray(size, 1);
    int count = 0;
    clock_gettime(CLOCK_MONOTONIC, &timeStart);
    count = numara5MasterThread(array, size);
    clock_gettime(CLOCK_MONOTONIC, &timeEnd);
    double time1 = computeTime(timeStart, timeEnd);
    printf("%.5lf ms: Avem %d elemente egale cu 5 in array\n", time1, count);
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


int numara5MasterThread(int *array, int size)
{
    pthread_t threads[NUM_THREADS];
    for (int i=0; i<NUM_THREADS; i++){
        ThreadArgs *args = createArgs(i, array, size);
        pthread_create(&threads[i], NULL, numara5Threads, (void *)args);
    }
    for (int i=0; i<NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }

    int finalCount = 0;
    for (int i=0; i<NUM_THREADS; i++){
        finalCount += globalCount[i];
    }

    return finalCount;
}

void* numara5Threads(void *myArgs) {
    ThreadArgs *args = (ThreadArgs *)myArgs;
    int myThreadID = args->threadID;
    int lenPerThread = args->size / NUM_THREADS;
    int start = args->threadID * lenPerThread;
    int *array = args->array;
    globalCount[myThreadID] = 0;
    for (int i = start; i < (start + lenPerThread); i++) {
        if (5 == array[i]) {
            globalCount[myThreadID]++;
    }
    }
    free(args);
    pthread_exit(NULL);
}

double computeTime(struct timespec start, struct timespec end) {
    double t;   
    t  = (end.tv_sec - start.tv_sec) * 1.0e3;  // -> ms
    t += (end.tv_nsec - start.tv_nsec) * 1.0e-6; // -> ms

    return t;
}

