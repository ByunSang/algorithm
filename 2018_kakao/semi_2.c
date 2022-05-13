#include <stdio.h>
#include <math.h>
#define MIN(x, y) (x) > (y) ? (y) : (x)
int main()
{
	int dolls[501] = {0,};
	int N , K = 0;
	double result = INFINITY;

	scanf ("%d %d", &N, &K);
	for (int i =0; i < N; i++)
	{
		int tmp = 0;
		scanf("%d", &tmp);
		dolls[i] = tmp;
	}

	for (int i=0; i<N-K+1; i ++)
	{
		int sum;
		double m;
		double dsum;
		for (int k = K; k < N - i + 1; k++){
			sum = 0;
			for (int j = i; j < k + i; j++){
				sum += dolls[j];
			}	
			
			 m = sum / (double)k;
			//printf ("middle : %f", middle);

			dsum = 0;
			for (int j = i; j < k + i; j++){
				dsum +=  (dolls[j] - m) * (dolls[j] - m);
			}
			//printf ("variance : %f", variance);
		
			result = MIN(result, sqrt(dsum / (double)k));
			printf ("result : %.11f\n", result);

		}
	}

	printf ("%.11f\n", result);

	return 0;
}
