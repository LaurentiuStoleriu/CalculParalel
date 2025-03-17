#include <stdio.h>
#include <omp.h>

#define ARRAY_SIZE_X 20000
#define ARRAY_SIZE_Y 20000
int a[ARRAY_SIZE_X][ARRAY_SIZE_Y];


int main()
{
    int i, j;
    double start, stop;

	for(i = 0; i < ARRAY_SIZE_X; i++)
		a[i][0] = 1;

    start = omp_get_wtime();
#pragma omp parallel for private(i)
    for(i = 0; i < ARRAY_SIZE_X; i++)    
        for(j = 1; j < ARRAY_SIZE_Y; j++)    
            a[i][j] = 1 * a[i][j-1];

    stop = omp_get_wtime();

    printf("LAST: %d in %lf s\n", a[ARRAY_SIZE_X-1][ARRAY_SIZE_Y-1], ((stop - start)));


}