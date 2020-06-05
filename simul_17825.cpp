#include <cstdio>
#include <queue>

using namespace std;

int horse[4] = {0,};
int total_num;

int path_1[30] = {0,2,4,6,8,10,12,14,16,18,20, 22,24,26,28,30,32,34,36,38,40, 0};
int path_2[30] = {13,16,19,25,30,35,40, 0};
int path_3[30] = {22,24,25,30,35,40,0,};
int path_4[30] = {28,27,26,25,30,35,40};

int horse_go_to_path[4] = {1,};

int where_horse(int num){
	return horse_go_to_path[num];
}
void dfs_17825(int cur_dise)
{
	q.push();
	while 
	return;
}

int main()
{
	int dise[10];
	int nas = 0;

	for (int i = 0; i < 10; i++){
		scanf("%d", &dise[i]);
	}

	path = where_horse(horse[0]);	
	switch (path) {
		case 1: 
			horse[0] += path_1[dise[0]];
			if (horse[0] == 10) {
				horse_go_to_path = 2; 
			}
			if (horse[0] == 20) horse_go_to_path = 3;
			if (horse[0] == 30) horse_go_to_path = 4;

		case 2:
			horse[0] += path_2[dise[0]];
		case 3:
		case 4:
	}
	horse[0][path] = path_1[dise[0]];
	if (horse[0] == 10) horse[][]

	

	for (int i = 1; i < 10; i++){
		
	}	
	
	return 0;
}
