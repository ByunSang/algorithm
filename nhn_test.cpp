#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;
#define MAX_NUM 101

string str[101][101];
string revo[101][101];
int real_w[51];
int real_w_cnt = 0;
bool check[101][101] = {false,};
void revolve_neon(int n, int w, int i, int offset)
{
	//cout << "real_w : " << w << endl;
	vector <pair <int,int>> v;
	for (int i = 0+offset; i < n-offset; i++){
		for (int j = 0+offset; j < n-offset; j++){
			if (i == offset || i == n-offset-1 || j == offset  || j == n-offset-1 ){
					if (i == offset) {
						v.push_back(make_pair(i,j));
						continue;
					}
					if (j == n-offset -1){
						 v.push_back(make_pair (i,j));
						continue;
					}
					if (j == offset){
						v.insert(v.begin(), make_pair(i,j));
						continue;
					}
					if (i == n-offset -1) {
						v.insert(v.begin(), make_pair(i,j));
						continue;
					}
			}
		}
	}
	
	for (int i = 0; i < v.size(); i++){
		//int d_i = v.at(i).first;
		//int d_j = v.at(i).second;
		
		int r_i = (i + w) % v.size();
		//cout << "i" << v.at(i).first << v.at(i).second << endl;
		
		//cout << "r" << v.at(r_i).first << v.at(r_i).second << endl;
		
		revo[v.at(r_i).first][v.at(r_i).second] = str[v.at(i).first][v.at(i).second];
	}
	//cout << "n" << n <<"n/2" << n/2 << endl;
	if (n % 2 != 0) {
		//cout << "str[][]" << str[n/2][n/2] << endl;
		revo[n/2][n/2] = str[n/2][n/2]; 
	}
	return;
}

int main() {
	int N = 0, W = 0;
	int circle_num[101];
	int s = 0;

	vector <pair<int,int>> circle_line;
	cin >> N >> W;

	for (int i =0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> str[i][j] ;
		}
	}
	circle_num[1] = 1;
	
	for (int i = 2; i < MAX_NUM; i++){
		circle_num[i] = 4 + 4*(i-2);
		//printf ("%d ", circle_num[i]);
	}

	for (int i = N; i >= 2; i = i - 2){
		int real_w = W;
		
		if (abs(real_w) > circle_num[i]){
			real_w = real_w % circle_num[i];
		}

		if (real_w < 0) real_w = circle_num[i] + real_w;

		//real_w[real_w_cnt++] = tmp;
		revolve_neon(N, real_w, i, s);
		
		W = W * -1;
		s++;
		//cout << tmp << endl;
	}
  
	//cout << "==== revo ====" << endl;
	for (int i = 0; i < N; i++){
		for (int j = 0; j< N; j++){
			cout << revo[i][j];	
		}
		cout << endl;
	}
	return 0;
}



