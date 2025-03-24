#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 4

int count = 0;
int* createArray(int size, int numai5);
void numara5Serial(int *array, int size);

int main() {
    int size = 10000;
    int *array = createArray(size, 0);
    count = 0;

    numara5Serial(array, size);

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

void numara5Serial(int *array, int size) {
    for (int i = 0; i < size; i++) {
        if (5 == array[i]) {
            count++;
        }
    }
}
