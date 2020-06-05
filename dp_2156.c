#include <stdio.h>
#define MAX_GLASS 10001
#define MAX(x,y) (((x) > (y)) ? (x) : (y))
int main()
{
    int N = 0;
    int arr[MAX_GLASS] = {0,};
    int dp[MAX_GLASS] = {0,};

    scanf("%d", &N);

    for (int i = 1; i < N+1; i++)
        scanf("%d", &arr[i]);

    dp[0] = 0;
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];

    for(int i = 3; i < N +1; i++){
        dp[i] = MAX(dp[i-2]+arr[i], dp[i-3]+arr[i-1]+arr[i]);
        /*point 2번 연속 안먹고 그 다음 큰 수를 먹을 수있다.*/
        dp[i] = MAX(dp[i], dp[i-1]);
    }

    printf("%d\n", dp[N]);
} 
