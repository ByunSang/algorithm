#include <stdio.h>

struct node{
	int right;
	int reft;
};

int main()
{
	int N; 
	struct node node[50] = {0,};
	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		int tmp ;
		scanf("%d", &tmp);
		printf ("%d %d\n", tmp , i);
	}
	return 0;
}
