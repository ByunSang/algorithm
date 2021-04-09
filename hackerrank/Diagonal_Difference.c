#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX_NUM 100
int arr[MAX_NUM][MAX_NUM] = {0, };

int main()
{
    int N = 0;
    int rtl1 = 0;
    int rtl2 = 0;
    int rtl_sum = 0;
    int ltr_sum = 0;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    
    rtl2 = N-1;
    for (int i = 0; i < N; i ++){
        for (int j = 0; j < N; j ++){
            if (rtl1 == i && rtl2 == j){ // rigth to left
                //printf ("rtl : %d i : %d j : %d\n", arr[i][j], i, j);
                rtl_sum += arr[i][j];
                rtl1++;
                rtl2--;
            } 
            if (i == j){  // left to rigth 
                //printf ("ltr : %d\n", arr[i][j]);
                ltr_sum += arr[i][j];
            }
        }
    }
    
    printf ("%d\n", abs(ltr_sum - rtl_sum));
    return 0;    
}


