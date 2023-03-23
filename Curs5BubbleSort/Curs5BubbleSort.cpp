#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
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
	DWORD starttime, elapsedtime;

	float *sir = (float*)malloc(N * sizeof(float));

	if (sir == NULL)
	{
		printf("eroare la alocarea sirului\n");
		exit(1);
	}

	starttime = timeGetTime();
	for (long i = 0; i < N; i++)
	{
		sir[i] = rand();
	}
	elapsedtime = timeGetTime() - starttime;
	for (long i = 0; i < 10; i++)				/////////////////
	{
		printf("sir[%d] = %f\n", i, sir[i]);
	}

	printf("%d ms umplerea sirului cu numere aleatorii\n", (int)elapsedtime);
	starttime = timeGetTime();
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
		printf("sir[%d] = %f\n", i, sir[i]);
	}
	elapsedtime = timeGetTime() - starttime;
	printf("%d ms sortarea sirului\n", (int)elapsedtime);

	return 0;
}

