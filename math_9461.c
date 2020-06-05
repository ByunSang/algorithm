#include <stdio.h>
int main(){

    long long arr[101] = {1,1,1,2,2,3,4,5,0,};
    int T = 0, N = 0;

    for (int i = 8; i < 100; i++){
        arr[i] = arr[i-1] + arr[i-5];
    }

    scanf("%d", &T);

    while(T--)  {
        scanf("%d", &N);
        printf ("%lld\n", arr[N-1]);
    }

} 
 


