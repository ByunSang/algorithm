#include <cstdio>
#include <queue>

using namespace std;
int N;
int M;
int Start;
bool V[1001] = { false, };
int arr[1001][1001] = { 0, };

void dfs(int start, bool* V, int arr[][1001], int N) 
{
	int i = 0;
	printf("%d ", start);
	V[start] = true;

	for (i = 1; i <= N; i++) {
		if (arr[start][i] && !V[i]) dfs(i, V, arr, N);
	}
	if (i == N) { 
		return;
	}
}

void init() 
{
	for (int i = 0; i < 1001; i++) {
		V[i] = false;
	}
}

void bfs(int Start, bool* V, int arr[][1001], int N) 
{
	queue <int> queue;
	
	queue.push(Start);

	while (!queue.empty()) {

		int front = queue.front();
		
		V[front] = true;
		printf("%d ", front);
		
		queue.pop();

		for (int i = 1; i <= N; i++) {
			if (arr[front][i] && !V[i]) {
				V[i] = true;
				queue.push(i);
			}
		}
	}
	
}
int main() 
{
	scanf("%d %d %d", &N, &M, &Start);

	for (int i = 1; i <= M; i++) 
	{
		int str = 0, dst = 0;
		scanf("%d %d", &str, &dst);
		arr[str][dst] = 1;
		arr[dst][str] = 1;
	}

	dfs(Start, V, arr, N);
	printf("\n");

	init();

	bfs(Start, V, arr ,N);
	printf("\n");
	return 0;
}
