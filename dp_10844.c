#include <stdio.h>

#define MOD 1000000000
int main(){
    int N = 0;
    long long dp[101][10];
    long long ret = 0;

    scanf("%d", &N);

    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;

    for(int i = 2; i <= N; i++){
        for (int j =0; j < 10; j++){
            if (j == 0)
                dp[i][j] = (dp[i-1][j+1]) % MOD;
            else if (j == 9)
                dp[i][j] = (dp[i-1][j-1]) % MOD;
            else
                dp[i][j] = ( dp[i-1][j-1] + dp[i-1][j+1] ) % MOD;
        }
    }

    for (int j =0; j < 9; j++)
        ret = ( ret + dp[N][j] ) % MOD;

    printf ("%llu\n", ret);
} 


