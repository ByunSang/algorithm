#include <stdio.h>

#define __5KG 5
#define __3KG 3
int main()
{
	int N = 0;
	scanf("%d", &N);
	
	if (N % __5KG == 0){
		printf("%d\n", N/5);
		return 0;
	}
	else if ((N%5)%3 == 0){
		printf("%d\n", (N/5)+ (N/5)/3);
	}
	else {
		int MAX = N / 5;
		for (int i = MAX; i > 0; i--)
		{
			if ((5*i) % 3 == 0){
				printf ("%d\n", i + (N-(5*i))/3);
			}
		}
	}

}
