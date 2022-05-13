#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int map[51][51] = {0,};
bool chk[51][51] = {false,};
int cnt = 0; 

struct dir
{
	int length;
	int width;
};

dir dir[4] = {{1,0}, {-1,0}, {0,-1}, {0,1}}; // µ¿¼­³²ºÏ

int dfs(int M, int N, int y, int x)
{
	chk[y][x] = true;
	for (int i =0; i< 4; i++)
	{
		int dx= x+dir[i].width;
		int dy= y+dir[i].length;

		if (map[dy][dx] && (dx < M) && (dy < N) && (dx >= 0) && (dy >=0))
		{
			if (!chk[dy][dx]){
				dfs(M,N, dy, dx);
			}
		}
	}
	return 0;
}

int bfs(int M, int N, int y, int x)
{
	queue<pair<int,int> > queue;

	queue.push(make_pair(y,x));

	while(!queue.empty())
	{
		int dy = queue.front().first;
		int dx = queue.front().second;

		chk[dy][dx] = true;
		printf ("%d %d\n", dy, dx);

		queue.pop();

		for (int i =0; i<4; i++)
		{
			int nx = dx + dir[i].width;
			int ny = dy + dir[i].length;
			
			//if (!chk[dy][dx] && map[dy][dx])
			if ((nx >= 0) && (ny >=0) && (nx < M) && (ny < N) && map[ny][nx] && !chk[ny][nx]){
				queue.push(make_pair(ny, nx));
			}
		}
	}
	printf ("\n");
	return 0;
}

int main()
{	
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int M, N, K;

		scanf("%d %d %d", &M, &N, &K);

		for (int i = 0; i < K; i++ )
		{
			int x, y;
			scanf ("%d %d", &x, &y);
			map[y][x] = 1;
		}

		for (int i = 0; i < N; i ++){
			for (int j = 0; j < M; j++){
				if (map[i][j] && !chk[i][j])
				//if (map[i][j])
				{
					//dfs(M,N,i,j);
					bfs(M,N,i, j); // 
					printf ("?? %d %d\n", j , i);
					cnt ++; // dfs¸¦ Ã³À½ Å¸´Â j, i°¡ °ð ¹èÃßÁö··ÀÌ? °¹¼ö
				}
			}
		}
		
		printf ("%d\n", cnt);
		cnt = 0;
		for (int i = 0; i < N; i ++){
			for (int j = 0; j < M; j++){
				map[i][j] = 0;
				chk[i][j] = false;
			}
		}
	}

	return 0;
}


