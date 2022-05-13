#include <iostream>

using namespace std;
#define PLUS 0
#define MINUS 1
#define MULTI 2
#define DEV 3
	
int result_min = 1000000001;
int result_max = -1000000001;

int N;
static void dfs(int* arr, int* op, int cnt, int cur)
{
	// arr : N  op : N-1
	if (cnt == N)
	{
		result_min = min(cur, result_min);
		result_max = max(cur, result_max);
	}

	if(op[PLUS]) 
	{
		op[PLUS]--;
		dfs(arr, op, cnt+1, cur + arr[cnt]);
		op[PLUS]++;
	}
	if(op[MINUS]) 
	{
		op[MINUS]--;
		dfs(arr, op, cnt+1, cur - arr[cnt]);
		op[MINUS]++;
	}
	if(op[MULTI]) 
	{	
		op[MULTI]--;
		dfs(arr, op, cnt+1, cur * arr[cnt]);
		op[MULTI]++;
	}
	if(op[DEV]) 
	{	
		op[DEV]--;
		dfs(arr, op, cnt+1, cur / arr[cnt]);
		op[DEV]++;
	}
}

int main()
{
	int arr[100] = {0,};
	int op[4];

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	for (int i = 0; i < 4; i++)
		cin >>  op[i];
	
	dfs(arr, op, 1, arr[0]);

	cout << result_min << endl;
	cout << result_max << endl; 
	
	return 0;
}
