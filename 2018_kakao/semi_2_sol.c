#include <stdio.h>
#include <math.h>




#define MIN(a,b) ((a)>(b)? (b):(a))



int N, K;

int a[500];



int main()

{

	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; ++i) {

		scanf("%d", &a[i]);

	}



	double result = 987654321;

	for (int i = 0; i < N - K + 1; ++i) {

		for (int k = K; k < N - i + 1; ++k) {

			int sum = 0;

			for (int j = i; j < i + k; ++j) {

				sum += a[j];

			}

			double m = sum / (double)k;



			double dsum = 0;

			for (int j = i; j < i + k; ++j) {

				dsum += (a[j] - m)*(a[j] - m);

			}

			result = MIN(result, sqrt(dsum/(double)k));
			printf("%.11f\n", result);
		}

	}



	printf("%.11lf\n", result);

	return 0;

}
