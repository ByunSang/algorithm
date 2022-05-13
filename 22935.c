#include <stdio.h>
//
//1 0001 % 32 --
//2 0010
//3 0011
//4 
//5
//6
//7
//8
//9
//10 
//11 1011
//12 1100
//13 1101
//14 1110		 
//15 1111 
//16 1110
//17 1101
//30 0001 1

//31 0010 2   % 31  == 0
//32 0011 3   % 31  2
//45 1111 15  % 31
//60 0001 1   % 31

//61 0010 2   % 31 == 
int main()
{
	int N = 0;
	int T = 0;

	scanf("%d", &T);

	while(T--){
		int strawberry[4] = {0,};
		int dev = 0;
		scanf("%d", &N);

		if (N % 30 == 0)
			N = (N/30 *2);
		else {
			N = N % 30;
			if (N > 15){
				N = 30 - N;
			}
		}
	
		printf("N : %d\n", N);
		for (int i = 3; i >= 0; i--)
		{
			if (N % 2) strawberry[i] = 1;
			N /= 2;
		}

		for (int i = 0; i < 4; i++)
		{
			if(strawberry[i]) printf("딸기");
			else printf("V");
		}
		printf("\n");
	}
	return 0;
}
