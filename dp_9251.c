#include <stdio.h>
#include <string.h>
#define MAX(x ,y) (x > y ? x : y) 
int main()
{
	char a[1001] = {0,};
	char b[1001] = {0, };

	scanf ("%s", a);
	scanf ("%s", b);

	int a_len = strlen(a);
	int b_len = strlen(b);
	int cnt = 0;
	for (int i = 0; i< a_len; i++){
		for (int j =0; j< b_len; j++){
			//	int new_cnt = 0;
			//if (a[i] == b[j]) cnt = MAX(cnt, ++new_cnt);
			if ((j <= i) && a[i] == b[j]) cnt ++;
			}
	}
	printf ("%s %s %d \n", a, b, cnt);
	return 0;
}
