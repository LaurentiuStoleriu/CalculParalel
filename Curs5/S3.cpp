#include <stdio.h>
#include <omp.h>

#define ARRAY_SIZE_X 20000
#define ARRAY_SIZE_Y 20000
int a[ARRAY_SIZE_X][ARRAY_SIZE_Y];


int main()
{
    int i, j;
    double start, stop;

	for(j = 0; j < ARRAY_SIZE_Y; j++)
		a[0][j] = 1;

    start = omp_get_wtime();
#pragma omp parallel for private(i)
    for(j = 0; j < ARRAY_SIZE_Y; j++)    
        for(i = 1; i < ARRAY_SIZE_X; i++)
            a[i][j] = 1 * a[i-1][j];

    stop = omp_get_wtime();

    printf("LAST: %d in %lf s\n", a[ARRAY_SIZE_X-1][ARRAY_SIZE_Y-1], ((stop - start)));


}