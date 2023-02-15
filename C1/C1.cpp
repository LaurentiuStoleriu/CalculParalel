#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MALLOC_SIZE 1
#define ARRAY_SIZE 10000000

char* array[ARRAY_SIZE];

int main(int argc, char* argv[])
{
	clock_t start, stop;
	start = clock();
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		array[i] = (char*)malloc(MALLOC_SIZE);
	}

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		free(array[i]);
	}
	stop = clock();

	printf("The time was %f miliseconds\n", ((double)(stop - start)));
	return 0;
}
