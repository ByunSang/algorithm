#include <stdio.h>

int main()
{
    int N ; 
    int arr[100] = {0, };
    
    int n_posive = 0;
    int n_negative = 0;
    int n_zero = 0;
    
    scanf("%d", &N);
    
    for (int i = 0; i<N; i++){
        scanf("%d", &arr[i]);
        if (arr[i] > 0) n_posive++;
        else if (arr[i] < 0) n_negative++;
        else n_zero++;
    }
    
    printf("%.7f\n%.7f\n%.7f", (float)n_posive/N , (float)n_negative/N , (float)n_zero/N);

}


