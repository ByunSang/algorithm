#include <stdio.h>
#define MAX 10000000

int main(){
    long N = 0;
    long long max = MAX / 6;

    scanf("%ld", &N);

    for (int i = 1; i < max +1 ; i++)
        if ((6 * (i * i) - (6 * i) + 2) >= 2 * N ) {
            printf ("%d\n", i);
            break;
        }

    return 0;
} 
