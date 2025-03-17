
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void swap(float *x, float *y)
{
    float tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

int main()
{
    long N = 100000;
    double starttime, elapsedtime;

    float *sir = (float*)malloc(N*sizeof(float));
    if (sir == NULL) {
        printf("eroare la alocarea sirului\n");
        exit(1);
    }

    starttime = omp_get_wtime();
    for (long i=0; i<N; i++){
        sir[i] = rand();
    }
    for (long i=0; i<10; i++){
        printf("sir[%ld] = %f\n", i, sir[i]);
    }
    elapsedtime = omp_get_wtime() ;

    printf("%lf ms umplerea sirului cu numere aleatorii\n", (elapsedtime-starttime)*1000);

    starttime = omp_get_wtime();
    char stop = 0;
    // for (long i=0; i<N; i++)
    // {
    //     stop = 1;
    //     for (long j=0; j<(N-1); j++)
    //     {
    //         if (sir[j] > sir[j+1])
    //         {
    //             swap(&sir[j], &sir[j + 1]);
    //             stop = 0;
    //         }
    //     }
    //     if (stop)
    //         break;
    // }

    omp_set_num_threads(2);
	for (long i = 0; i < N; i++)
	{
		long prim = i % 2;
#pragma omp parallel for shared(sir,prim)
		for (long j = prim; j < (N - 1); j += 2)
		{
			if (sir[j] > sir[j + 1])
			{
				swap(&sir[j], &sir[j + 1]);
			}
		}
	}

    for (long i = 0; i < 10; i++)
    {
        printf("sir[%ld] = %f\n", i, sir[i]);
    }
    elapsedtime = omp_get_wtime();    
    
    printf("%lf ms sortarea sirului\n", (elapsedtime-starttime)*1000);

    return 0;
}