 
#include <stdio.h>
#define MIN(x,y) (((x) <= (y)) ? (x) : (y))

int main()
{
    int N = 0;
    long arr[1001][3] = {0,};
    long d[1001][3] = {0,};

    scanf("%d", &N);

    for (int i =1; i <=N; i++)
        scanf("%ld %ld %ld", &arr[i][0], &arr[i][1], &arr[i][2]);

    for (int i =1; i <= N; i ++){
        d[i][0] = MIN(d[i-1][1], d[i-1][2]) + arr[i][0];
        d[i][1] = MIN(d[i-1][0], d[i-1][2]) + arr[i][1];
        d[i][2] = MIN(d[i-1][0], d[i-1][1]) + arr[i][2];
    }

    printf ("%ld\n", MIN(MIN(d[N][0], d[N][1]), d[N][2]));
    return 0;
} 


