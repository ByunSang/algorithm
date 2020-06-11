#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
#define MAX_NUM 101

string str[101][101];
void revolve_neon(int w, int n, int s)
{
	
	for (int i = 0+s; i < n-s; i ++){
		for (int j = 0+s; j < n-s; j ++){
			cout << str[i][j];
		}
		cout << endl;
	}
	
	return;
}

int main() {
	int N = 0, W = 0;
	int circle_num[101];
	int s = 0;

	cin >> N >> W;
	
	for (int i = 0; i < N; i ++){
		for (int j = 0; j < N; j ++)
			cin >> str[i][j];
	}

	circle_num[1] = 1;
	
	for (int i = 2; i < MAX_NUM; i++){
		circle_num[i] = 4 + 4*(i-2);
		//printf ("%d ", circle_num[i]);
	}
	
	for (int i = N; i > 2; i = i - 2){
		int real_W = W;
		
		if (abs(real_W) > circle_num[i]){
			real_W = real_W % circle_num[i];
		}

		if (real_W < 0) real_W = circle_num[i] + real_W;

		revolve_neon(real_W, N ,s);
		
		W = W * -1;
		s ++;
		cout << real_W << endl;
	}
	
	return 0;
}
