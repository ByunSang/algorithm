#include <stdio.h>
#include <stdlib.h>

#define MAX(x , y) (((x) > (y)) ? (x) : (y)); 

int main()
{
    int N;
    long *arr;
    long max = 0;
    int max_candle_num = 0;
    scanf ("%d", &N);
    
    arr = malloc(N * sizeof(long));
    
    for (int i = 0; i < N; i ++){
        scanf ("%ld", &arr[i]);
        max = MAX(max, arr[i]);
    }
    
    for (int i = 0; i < N; i ++){
        if (max == arr[i]) max_candle_num++;
    }    
    printf ("%d", max_candle_num);
    
    return 0;
}


