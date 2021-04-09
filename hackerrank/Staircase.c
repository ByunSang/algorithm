#include <stdio.h>

int main()
{
    int N;
    int M;
    scanf("%d", &N);
    
    M=N;
    
    for (int j = 0; j<N; j++){
        for (int i =0; i<N; i++){
            if (i < M-1) printf(" ");
            else {
                printf("#");
            }
        }
        printf("\n");
        M--;
    }
}


