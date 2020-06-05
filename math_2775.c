#include <stdio.h>

int main()
{
    int k , n = 0;
    int count = 0;
    int arr[16][16] = {0,};

    for (int i = 0; i < 15; i++){
        arr[0][i] = i;
        arr[i][1] = 1;
        arr[i][0] = 0;
    }

    for (int i = 1; i < 15; i++){
        for(int j = 1; j < 15; j++){
            arr[i][j] = arr[i-1][j] + arr[i][j-1];
        }
    }

    scanf("%d", &count);

    while(count--){
        scanf("%d", &k);
        scanf("%d", &n);
        if (k > 15 || n > 15) {
            printf("-1\n");
            return 0;
        }
        printf("%d\n", arr[k][n]);
    }
/*
    for (int i = 14; i >= 0; i--){
        for(int j = 0; j < 15; j++){
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
 */
} 
