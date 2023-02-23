#include <stdio.h>
#include <math.h>
#include <windows.h>


const long int VERYBIG = 100000;
int main(void)
{
	int i;
	long int j, k, sum;
	double sumx, sumy, total;
	DWORD starttime, elapsedtime;
	printf("Non-Parallel Timings for %d iterations\n\n", VERYBIG);
	for (i = 0; i < 6; i++)
	{
		starttime = timeGetTime();
		sum = 0;
		total = 0.0;

		for (j = 0; j < VERYBIG; j++)
		{
			sum += 1;
			sumx = 0.0;
			for (k = 0; k < j; k++)
				sumx = sumx + (double)k;
			sumy = 0.0;
			for (k = j; k > 0; k--)
				sumy = sumy + (double)k;
			if (sumx > 0.0) total = total + 1.0 / sqrt(sumx);
			if (sumy > 0.0) total = total + 1.0 / sqrt(sumy);
		}
		elapsedtime = timeGetTime() - starttime;
		printf("Time Elapsed %10d mSecs Total = %lf Check Sum = %ld\n", (int)elapsedtime, total, sum);
	}  
	return 0;
}
