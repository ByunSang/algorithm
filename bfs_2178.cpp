#include <cstdio>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

#define MAX_SIZE 101

int map[MAX_SIZE][MAX_SIZE] = {0,};
int check[MAX_SIZE][MAX_SIZE] = {0,};
int via[MAX_SIZE][MAX_SIZE] = {false,};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
static int bfs_maze(int max_y, int max_x)
{   
    queue<pair<int, int> > q;
    q.push(make_pair(0,0));
    int min_check = 0;
    
    while (!q.empty()){
        int x = q.front().second;
        int y = q.front().first;
        
        via[y][x] = true;
        
        q.pop();
        
        for (int i = 0; i < 4; i++){
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            
            if (next_x >= 0 && next_y >= 0 && next_x < max_x && next_y < max_y && 
              !via[next_y][next_x] && (check[next_y][next_x] == 0) && map[next_y][next_x])
            {   
                via[next_y][next_x] = true;
                check[next_y][next_x] = check[y][x] + 1;
                q.push(make_pair(next_y, next_x));
                min_check++;
            }
        }
    }
    return min_check;
}
int main()
{
    int N, M, min_check;
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i <N; i++){
        string tmp = "";
        cin >> tmp;
        for (int j = 0; j < M; j++)
            map[i][j] = tmp[j] - '0';
    }       
    min_check = bfs_maze(N, M);
 /*   
    for (int i = 0; i <N; i++){
        for (int j = 0; j < M; j++){
            printf("%d ", check[i][j]);
        }   
        printf("\n");
    }   
  */ 
    printf("%d\n" , check[N-1][M-1] + 1);
    return 0;
}
