#include <stdio.h>
#define MAX(x,y) (((x) > (y)) ? (x) : (y))
int main(){
    int N = 0;
    int arr[1001] = {0,};
    int dp[1001] = {0,};
    int max = 0;
    
    scanf("%d", &N);
    
    for (int i = 1; i<= N; i++){
        scanf("%d", &arr[i]);
        dp[i] = 1;
    }
    if (arr[1] < arr[2]) dp[2]= 2;
    for (int i= 2; i <= N; i++){
        max = 1;
        for (int j = i-1; j >= 1; j--)
            if (arr[i] > arr[j]){ 
                max = MAX(max,dp[j]);
                dp[i] = max +1;
            }
    }
    for (int i =1; i <= N; i++)
        max = MAX(dp[i],max);
    printf ("%d\n", max);
}
