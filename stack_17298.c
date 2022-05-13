#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int main()
{
	int N;
	int *arr = NULL;

	scanf("%d\n", &N);

	arr = (int*)malloc(N * sizeof(int));

	memset(arr, -1, N);
	
	for(int i =0; i < N; i++){
		scanf("%d", &arr[i]);	
	}

	for(int i =0; i < N; i++){
		bool find_flag = false;
		if (i == N-1) printf("-1\n");

		for(int j = i; j < N; j++){
			if(arr[i] < arr[j]){
				printf("%d", arr[j]);
				find_flag = true;
				break;
			}
		}	
		if(find_flag == false) printf("-1");
		printf(" ");
	}

	if (arr) free(arr);
	
	return 0;
}
