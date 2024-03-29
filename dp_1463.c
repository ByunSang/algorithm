#include <stdio.h>
#define MIN(x,y) (((x) <= (y)) ? (x) : (y))

int main()
{
    int N = 0, n =0;

    int d[1000001] = {0,};

    scanf("%d", &N);

    d[1] = 0;

    for (int i = 2; i <= N; i++){
        d[i] = d[i -1] +1;
        if (i % 3 == 0) d[i] = MIN (d[i], d[i/3] + 1);
        if (i % 2 == 0) d[i] = MIN (d[i], d[i/2] + 1);
    }

    printf ("%d\n", d[N]);
} 
