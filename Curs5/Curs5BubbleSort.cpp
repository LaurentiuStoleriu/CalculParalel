#include <stdio.h>
#include <stdlib.h>
#include <ctime>
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

	double elapsedTime;
	double startTime;

	float *sir = (float*)malloc(N * sizeof(float));

	if (sir == NULL)
	{
		printf("eroare la alocarea sirului\n");
		exit(1);
	}


	startTime = omp_get_wtime();//clock();
	for (long i = 0; i < N; i++)
	{
		sir[i] = rand();
	}
	elapsedTime = omp_get_wtime() - startTime;//static_cast<double>(clock() - startTime) / CLOCKS_PER_SEC;


	for (long i = 0; i < 10; i++)				/////////////////
	{
		printf("sir[%ld] = %f\n", i, sir[i]);
	}

	printf("%d ms umplerea sirului cu numere aleatorii\n", (int)(elapsedTime*1000.0));

	
	startTime = omp_get_wtime();//clock();
	char stop = 0;

	for (long i = 0; i < N; i++)
	{
		stop = 1;
		long jini = i % 2;
#pragma omp parallel for shared(sir,jini)
		for (long j = jini; j < (N - 1); j+=2)
		{
			if (sir[j] > sir[j + 1])
			{
				swap(&sir[j], &sir[j + 1]);
				stop = 0;
			}
		}
		if (stop)
			break;
	}

	for (long i = 0; i < 10; i++)
	{
		printf("sir[%ld] = %f\n", i, sir[i]);
	}
	elapsedTime = omp_get_wtime()-startTime;//static_cast<double>(clock() - startTime) / CLOCKS_PER_SEC;
	printf("%d ms sortarea sirului\n", (int)(elapsedTime*1000.0));

	return 0;
}

