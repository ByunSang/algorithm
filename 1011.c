#include <stdio.h>
#define MAX_SIZE 101

int main()
{
	int arr[MAX_SIZE]= {0,};
	int N = 0;
	int index = 0;

	arr[1] = 3;
	
	for (int i = 1; i < MAX_SIZE; i++)
		arr[i+1] = arr[i]+ (2 * i + 2);
	
	scanf("%d", &N);

	for (int i =0; i < MAX_SIZE; i++){
		if (arr[i] <= N && N <= arr[i+1]) {
			printf ("%d %d %d \n", arr[i], arr[i+1], i);
			index = i;
		}
	}
	printf ("%d\n", index*2 +1);

	return 0 ;
}
