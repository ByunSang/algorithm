#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_NUM 26

struct dir{
	int y, x;
};

struct home{
	int y, x;
};

int map[MAX_NUM][MAX_NUM] = {0,};
bool via[MAX_NUM][MAX_NUM] = {false,};
dir dir[4] = { {1,0}, {-1,0}, {0,1}, {0,-1}};

int house_hold = 0;
vector <int> v;

int num = 0;
int house_num = 0;
void dfs_2667(int i, int j)
{
	//map[i][j] = 0;
	via[i][j] = true;
	house_num ++;
	for(int k =0; k < 4; k++){
		int dx = j + dir[k].x;
		int dy = i + dir[k].y;

		if (dx < num && dy < num && dx >= 0 && dy >=0){
			//if (map[dy][dx] == 1){
			if ((map[dy][dx] == 1) && (!via[dy][dx])){
				dfs_2667(dy, dx);
			}
		}
	}
}

int main()
{
	scanf ("%d", &num);
	
	for (int i = 0; i < num; i++){
		for (int j = 0; j < num; j++){
			scanf ("%1d", &map[i][j]);
		}
	}
	
	for (int i = 0; i < num; i++){
		for (int j = 0; j < num; j++){
			if (map[i][j] == 1 && !via[i][j]) {
				house_num = 0;
				dfs_2667(i,j);
				v.push_back(house_num);
			}
		}
	}
	sort(v.begin(), v.end());
	printf ("%lu\n", v.size());
	for (int i = 0 ; i < v.size(); i++){
		printf ("%d\n", v[i]);
	}

	return 0;
}



