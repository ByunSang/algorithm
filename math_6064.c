#include <stdio.h>
int gcd (int a, int b){
    int c ;
    while (b!=0){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int main(){

    int N = 0, M=0, x=0, y=0, T=0;

    scanf("%d", &T);

    while(T--){
        scanf("%d %d %d %d", &M, &N, &x, &y);
        int year = -1;
        for (int i =0; x+i*M <= lcm(N,M); i ++){
            if (y == ((x+i*M) % N) ||
                y == N && ((x+i*M) % N == 0)) {
                year = x+i*M;
                break;
            }

        }
        printf ("%d\n", year);
    }

    return 0;
} 
 


