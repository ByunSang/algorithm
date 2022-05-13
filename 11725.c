#include <stdio.h>
#define MAX 1000
int main()
{
	int dp[MAX] = {0,};
	int N = 0;
	scanf("%d", &N);
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= N; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}

	printf("%d\n", dp[N] % 10007);
}
