#include <stdio.h>
#include <stdlib.h>

#define MAX(x , y) (((x) > (y)) ? (x) : (y))

int main(void)
{
	int N;
	int W;

	int value[101];
	int weight[101];

	int backpack[101][100001] = {0,};

	printf("start \n");

	scanf("%d %d", &N, &W);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d", &weight[i], &value[i]);
	}

	for (int w = 1; w <= W; w++)
	{
		for (int i = 1; i <= N; i++)
		{
			if (weight[i] > w){
				backpack[i][w] = backpack[i-1][w];
			}
			else {
				backpack[i][w] = MAX((backpack[i-1][w-weight[i]]+value[i]), backpack[i-1][w]);
			}
		}
	}
	
	printf("%d\n", backpack[N][W]);

	return 0;
}
