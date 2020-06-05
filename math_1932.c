#include <stdio.h>
#define MAX(x,y) (( (x) > (y) ) ? (x) : (y))

int main()
{
    int N = 0;
    long long arr[501][501] = {0, };
    long long d[501][501] = {0, };
    int max = 0;

    scanf("%d", &N);

    for (int i=1; i <= N; i++)
        for(int j =1; j <= i; j++)
            scanf("%lld", &arr[i][j]);

    for (int i =1; i<=N; i++){
        for (int j=1; j<=i; j ++){
            if (j == 1) d[i][j] = d[i-1][j] + arr[i][j];
            d[i][j] = MAX(d[i-1][j], d[i-1][j-1]) + arr[i][j];
            //printf ("%lld\t", d[i][j]);
        }
        //printf ("\n");
    }   
    for (int i = 1; i <= N; i++){
        max = MAX(max, d[N][i]);
    }

    printf ("%d\n", max);

    return 0;
} 
 


