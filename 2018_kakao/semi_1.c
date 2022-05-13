#include <stdio.h>
#include <stdlib.h>
int money[1001] = {0,};

void calc_money(int i, int semi, int final)
{
	if (semi == 1) money[i] += 5000000;
	else if (semi >=2 && semi <= 3) money[i] += 3000000;
	else if (semi >=4 && semi <= 6) money[i] += 2000000;
	else if (semi >=7 && semi <= 10) money[i] += 500000;
	else if (semi >=11 && semi <= 15) money[i] += 300000;
	else if (semi >=16 && semi <= 21) money[i] += 100000;
	else money[i] += 0;
	
	if (final == 1) money[i] += 5120000;
	else if (final >=2 && final <=3) money[i] += 2560000;
	else if (final >=4 && final <=7) money[i] += 1280000;
	else if (final >=8 && final <=15) money[i] += 640000;
	else if (final >=16 && final <=31) money[i] += 320000;
	else money[i] += 0;
}

int main()
{
	int N ;
	int semi, final;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf ("%d %d", &semi, &final);
		calc_money(i, semi, final);	
	}
	
	for (int i = 0; i<N; i++)
		printf("%d\n", money[i]);

	return 0;
}
