#include <stdio.h>
#include <math.h>
#define MIN(a,b) ((a)>(b)? (b):(a))
int main()
{
	int dolls[501] = {0,};
	int N , K = 0;
	double middle= 0;
    double sum = 0;
	double variance = 9987654321;
	double deviation = 0;

	scanf ("%d %d", &N, &K);
	for (int i =0; i < N; i++)
	{
		int tmp = 0;
		scanf("%d", &tmp);
		dolls[i] = tmp;
	}

	for (int i=0; i<N-K+1; ++i)
	{
        sum = 0;
		middle = 0;
		deviation = 0;
		for (int j = i; j < K + i; ++j){
			sum += dolls[j];
		}	
		
		middle = sum / (double)K;
		for (int j = i; j < K + i; j++){
			deviation +=  (double)((dolls[j] - middle) * (dolls[j] - middle));
		}
		variance = MIN(variance, sqrt(deviation/ (double)K));
		printf ("%f \n", variance );	
	}

	printf ("%.11f\n", variance);


	return 0;
}


