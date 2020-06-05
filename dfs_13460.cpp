#include <cstdio>
#include <queue>
#include <iostream>
#include <string>
#define MAX_SIZE 11
using namespace std;

struct status_ball
{
	int depth;
	int red_x, red_y;
	int blue_x, blue_y;
};
char map[MAX_SIZE][MAX_SIZE] = {'#', };
bool via[MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE] = {false ,};
int where_red[MAX_SIZE][MAX_SIZE] = {0,};
int where_blue[MAX_SIZE][MAX_SIZE] = {0,};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void move_ball(int* x, int* y, int i, int max_x, int max_y)
{
	int next_x = *x;
	int next_y = *y;
	
	while(1)
	{
		switch (i) {
			case 0 : next_x += dx[i]; break;
			case 1 : next_x += dx[i]; break;
			case 2 : next_y -= dy[i]; break;
			case 3 : next_y -= dy[i]; break;
		}

		if (map[next_x][next_y] == '#'){
			switch (i){
				case 0 : 
					*x = next_x - dx[i];
					break;
				case 1 :
					*x = next_x - dx[i];
					break;
				case 2 :
					*y = next_y + dy[i];
					break;
				case 3 :
					*y = next_y + dy[i];
					break;
			}
			//printf (" # %d %d\n", *x, *y);
			break;
		}
		else if (map[next_x][next_y] == 'O'){	
			*x = next_x;
			*y = next_y;
			//printf (" 0 %d %d\n", *x, *y);
			break;
		}
		else {
			//printf ("  %d %d\n", *x, *y);
			*x = next_x;
			*y = next_y;
		}
	}
	return ;
}
static int dfs_ball_escape(int max_y, int max_x, int init_red_x, int init_red_y, int init_blue_x, int init_blue_y)
{
	struct status_ball ball;
	queue <status_ball> q;

	ball.depth = 0;
	ball.red_x = init_red_x;
	ball.blue_x = init_blue_x;
	ball.red_y = init_red_y;
	ball.blue_y = init_blue_y;

	via[init_red_y][init_red_x][init_blue_y][init_blue_x] = true;
	
	q.push(ball);

	while(!q.empty()){
		struct status_ball cur;
		cur = q.front();
		q.pop();
		//via[cur.red_y][cur.red_x][cur.blue_y][cur.blue_x] = true;
		//	printf ("via %d %d %d %d\n", cur.red_x,cur.red_y,cur.blue_x,cur.blue_y);
		
		if (cur.depth > 10 ) return -1; 

		if (map[cur.red_x][cur.red_y] == 'O') {
			//printf ("finish %d %d \n", cur.red_x, cur.red_y);
			return cur.depth;
		}	


		for (int i = 0; i < 4; i++){
			int rx = cur.red_x;
			int ry = cur.red_y;
			int bx = cur.blue_x;
			int by = cur.blue_y;
			int depth = cur.depth;	
			//조건문 길어지니까, 움직이고 나서 결과값을 가져오자
			move_ball(&rx,&ry, i, max_x, max_y);
			move_ball(&bx,&by, i, max_x, max_y);
            if (map[bx][by] == 'O') continue;
			if (rx == bx && ry == by) {
				switch (i){
					case 0 : cur.red_x > cur.blue_x ? bx -- : rx --; break;
					case 1 : cur.red_x > cur.blue_x ? rx ++ : bx ++; break;
					case 2 : cur.red_y > cur.blue_y ? by -- : ry --; break;
					case 3 : cur.red_y > cur.blue_y ? ry ++ : by ++; break;
				}
			}
			//printf ("red located  %d %d \n", rx, ry);
			//printf ("blue located %d %d \n", bx, by);
					
			if (!via[ry][rx][by][bx]){
				struct status_ball next;	
				next.red_x = rx;
				next.red_y = ry;
				next.blue_x = bx;
				next.blue_y = by;
				next.depth = depth +1;

				//printf ("push next ball[%d] %d %d %d %d\n",next.depth, rx, ry, bx, by );
				q.push(next);
				via[ry][rx][by][bx] = true;
			}
		}
	}
	
	return -1;
}

int main ()
{

	int N, M;
	int ret;
	int init_red_x;
	int init_red_y;
	int init_blue_x;
	int init_blue_y;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++){
		string tmp = "";
		cin >> tmp ;
		for (int j = 0; j < M; j++ ){
			map[i][j] = tmp[j];
			if (map[i][j] == 'B'){
				init_blue_x = i;
				init_blue_y = j;
			}
			if (map[i][j] == 'R'){
				init_red_x = i;
				init_red_y = j;
			}
		}
	}
	/*
	for (int i = 0; i < N; i++){
		for (int j=0; j < M; j++){
			printf ("%c",map[i][j]);
		}
		printf ("\n");
	}*/
	ret = dfs_ball_escape(N, M, init_red_x, init_red_y, init_blue_x, init_blue_y);
		
	printf ("%d\n", ret);
	return 0;
}
