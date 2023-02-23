#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cilk/cilk.h>
#include <tbb/scalable_allocator.h>

#define MALLOC_SIZE 1
#define ARRAY_SIZE 10000000

char* array[ARRAY_SIZE];

int main(int argc, char* argv[])
{
	clock_t start, stop;
	start = clock();
	cilk_for(int i = 0; i < ARRAY_SIZE; i++)
	{
		array[i] = (char*)scalable_malloc(MALLOC_SIZE);
	}

	cilk_for(int i = 0; i < ARRAY_SIZE; i++)
	{
		scalable_free(array[i]);
	}
	stop = clock();

	printf("The time was %lf miliseconds\n", ((double)(stop - start)));
	return 0;
}
