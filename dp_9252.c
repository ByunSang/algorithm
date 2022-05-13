#include <stdio.h>
#include <string.h>

static void print(int lcs[][1001], char* str1, char* str2, int i, int j)
{
	if (lcs[i][j] == 0) return;
	if(str1[i-1] == str2[j-1])
	{
		print(lcs, str1, str2, i-1, j-1);
		printf("%c", str1[i-1]);
	}
	else lcs[i-1][j] > lcs[i][j-1] ? print(lcs, str1, str2, i-1, j) : print(lcs, str1, str2, i, j-1);
}

int main()
{
	char str1[1001];
	char str2[1001];
	int str1_len;
	int str2_len;
	int lcs[1001][1001] = {0,};
	int i = 0, j = 0;
	scanf("%s", str1);
	scanf("%s", str2);
	
	str1_len = strlen(str1);
	str2_len = strlen(str2);

	for (i = 1; i <= str1_len; i++)
	{
		for (j = 1; j <= str2_len; j++)
		{
			if (str1[i-1] == str2[j-1]) lcs[i][j] = lcs[i-1][j-1] + 1;
			else lcs[i][j] = lcs[i-1][j] > lcs[i][j-1] ? lcs[i-1][j] : lcs[i][j-1];
				
		}
	}
	
	printf("  ");
	for (i = 0; i < str1_len; i++)
		printf("%c ", str1[i]);

	printf("\n");
	for (i = 1; i <= str1_len; i++)
	{
		printf("%c ", str2[i-1]);
		for (j = 1; j <= str2_len; j++)
		{
			printf("%d ", lcs[j][i]);
		}
		printf("\n");
	}
	printf("%d %d\n", i, j);
	printf("%d\n", lcs[i-1][j-1]);
	print(lcs, str1, str2, i-1, j-1);
	return 0;
}

