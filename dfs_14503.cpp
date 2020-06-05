#include <cstdio>
#include <iostream>
#include <queue>
#define MAX_SIZE 51
using namespace std;

struct status_bot{
	int r;
	int c;
	int d;
};

int map[MAX_SIZE][MAX_SIZE] = {0,};

struct move_dir
{
	int r,c;
};

move_dir move_dir[4] = { {-1,0}, {0,1}, {1,0}, {0,-1} };

static int clean_dfs(int r, int c, int d, int N, int M)
{
	int ans = 0;
	status_bot init;
	
	init.r = r;
	init.c = c;
	init.d = d;

	queue <status_bot> q; 
	q.push(init);

	while (!q.empty()){
		status_bot cur = q.front();
		int new_r = cur.r;
		int new_c = cur.c;
		int new_d = cur.d;
		int flag = 0;

		// 지금 자리 청소
		if (!map[new_r][new_c]){
			//printf ("x: %d y: %d %d\n", new_c, new_r, new_d);
			//via[new_r][new_c] = true;
			map[new_r][new_c] = 2;
            ans ++;
		}
		q.pop();
	
		// 4방향 탐색
		for (int i = 0; i < 4; i ++ ){
			int next_d = (new_d + (3 - i)) % 4;
			int next_r = new_r + move_dir[next_d].r;
			int next_c = new_c + move_dir[next_d].c;

			if (0 <= next_r && 0 <= next_c && N > next_r && M > next_c && !map[next_r][next_c]){
				status_bot next;
				next.r = next_r;
				next.c = next_c;
				next.d = next_d;
				q.push(next);
				flag = 1;
				break;
			}
			/*
			//왼쪽 방향이 총소를 했거나, 청소할 공간이 없다면 한번 더 회전
			if (map[next_r][next_c] || via[next_r][next_c]) continue;
			*/
		}
			
		// 4바퀴 다돌면 flag on 
		if (!flag){
			//현재 방향 기준으로 뒤로 후진
			int next_r = new_r - move_dir[new_d].r;
			int next_c = new_c - move_dir[new_d].c;

			//printf ("dir == 4 %d %d %d\n", next_r, next_c, new_d);
			// 벽이거나 청소한 곳이라면 
			if (next_r <= N && next_r >= 0 && next_c <= M && next_c >= 0 && (map[next_r][next_c] != 1 )){
				status_bot next;
				next.r = next_r;
				next.c = next_c;
				next.d = new_d;
				q.push(next);
			}
			else break;
		}
	}

	return ans;
}
int main ()
{	
	int ret = 0;
	int N = 0, M = 0;
	int r = 0, c = 0, d = 0;
	int i = 0, j=0;
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &r, &c, &d);

	for (i = 0; i< N; i++){
		for (j =0; j< M; j++){
			scanf("%d", &map[i][j]);
		}
	}
/*
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (via[i][j]) printf ("1 ");
			else printf ("0 ");
		}
		printf ("\n");
	}
*/
	ret = clean_dfs(r, c, d, N, M);
	printf ("%d\n", ret);
	return 0;
}


