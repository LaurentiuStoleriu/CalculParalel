#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <cilk/cilk.h>
#include <cilk/reducer_opadd.h>

const long int VERYBIG = 100000;

int main(void)
{
	int i;
// 	long int sum;
// 	double total;
	DWORD starttime, elapsedtime;
	printf("Non-Parallel Timings for %d iterations\n\n", VERYBIG);
	for (i = 0; i < 6; i++)
	{
		starttime = timeGetTime();
// 		sum = 0;
// 		total = 0.0;
		cilk::reducer_opadd<long int> sum(0);
		cilk::reducer_opadd<double> total(0.0);


		//for (int j = 0; j < VERYBIG; j++)
		cilk_for(int j = 0; j<VERYBIG; j++)
		{
			long int k;
			double sumx, sumy;

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
		printf("Time Elapsed %10d mSecs Total = %lf Check Sum = %ld\n", (int)elapsedtime, total.get_value(), sum.get_value());
	}  
	return 0;
}


