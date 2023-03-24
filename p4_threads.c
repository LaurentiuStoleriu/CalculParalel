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
int* createArray(int size, int numai5);
//void numara5Serial(int *array, int size);
void numara5Threaded(void *args);

int main() 
{
    int size = 100000;
    int *array = createArray(size, 1);
    count = 0;

    pthread_t threadID[NUM_THREADS];
    //numara5Serial(array, size);

    for(int id=0; id<NUM_THREADS; id++)
    {
        ThreadArgs *myArgs = createArgs(id, array, size);   /////////////////////////////
        pthread_create(&threadID[id], NULL, numara5Threaded, (void *)myArgs);
    }

    for(int id=0; id<NUM_THREADS; id++)
    {
        pthread_join(&threadID[id], NULL);
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

void numara5Serial(int *array, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        if (5 == array[i]) // Yoda script
        {
            count++;
        }
    }
}

