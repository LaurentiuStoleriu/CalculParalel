#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <omp.h>

#define MALLOC_SIZE 1
#define ARRAY_SIZE_X 20000
#define ARRAY_SIZE_Y 20000
double a[ARRAY_SIZE_X][ARRAY_SIZE_Y];

int main()
{
	//clock_t start, stop;
    double start, stop;
	start = omp_get_wtime();//clock();
    int i, j;

//initializare
    for(i = 0; i < ARRAY_SIZE_X; i++)
    {
        a[i][0] = 1.0;
    }

//work
#pragma omp parallel for private (j)
	for(i = 0; i < ARRAY_SIZE_X; i++)
	{
        for(j = 1; j < ARRAY_SIZE_Y; j++)
        {
            a[i][j] = 1 * a[i][j-1];
        }
	}

	stop = omp_get_wtime();//clock();

	printf("LAST: %le   in %lf miliseconds\n", a[ARRAY_SIZE_X-1][ARRAY_SIZE_Y-1], ((double)(stop - start)*1000));
	return 0;
} 
