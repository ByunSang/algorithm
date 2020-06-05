#include <stdio.h>
#define MAX 2100000000
int main(void){

    long A = 0;
    long B = 0;
    long C = 0;
    long reven = 0;
    scanf ("%ld %ld %ld", &A, &B, &C);
    if (B >= C) {
        printf("-1\n");
    } 
    else printf ("%ld\n", A / (C-B) +1);

    return 0;
} 
