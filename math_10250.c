#include <stdio.h>

int main(){
    int H , W = 0;
    int F, num_of_family = 0;
    int N = 0;
    int count = 0;

    scanf("%d", &count);
    while (count--){

        scanf("%d %d %d", &H, &W, &N);
        
        if (N % H == 0 ) {
            num_of_family = N / H ;
            F = H;
        }
        else  {
            num_of_family = (N / H) + 1;
            F = N % H ;
        }
        printf ("%d\n", (F*100) + num_of_family);

    }

} 
