#include <stdio.h>
#include <stdlib.h>
int main(void){

    int n5KG = 0;
    int n3KG = 0;
    int N = 0;

    scanf("%d", &N);

    if ((N % 5) == 0 || (N % 5) == 3)  {
        n5KG = N / 5;
        n3KG = (N % 5) == 0 ? 0 : 1;
        printf ("%d \n", n5KG + n3KG);
        return 0;
    }


    for (int i = N; i > 0; i = i-3 ){
        if ((i % 5) == 0){
            printf ("%d \n", (i / 5) +  ((N-i) / 3));
            return 0;
        }
    }

    if ((N % 3) == 0){
        printf ("%d \n", N / 3);
        return 0;
    }

    else printf("-1\n");

    return 0;

} 
