#include <iostream>

using namespace std;
int a[50][2];

void preorder(int x) {
	if (x == -1) return ;
	cout << (char)(x+'A');
	preorder(a[x][0]); // left child
	preorder(a[x][1]); // right child
}

void inorder(int x) {
	if (x == -1 ) return ;
	inorder(a[x][0]);
	cout << (char)(x + 'A');
	inorder(a[x][1]);
}

void postorder(int x ){
	if (x == -1) return;
	postorder(a[x][0]);
	postorder(a[x][1]);
	cout << (char)(x + 'A');
}

int main(){

	int N;
	cin >> N;

	for (int i = 0; i < N; i++){
		char x,y,z;
		cin >> x >> y >> z;
		a[x - 'A'][0] = y != '.' ? y - 'A' : -1;
		a[x - 'A'][1] = z != '.' ? z - 'A' : -1;
	}
	preorder(0); // A is parent node;
	cout << '\n';
	inorder(0); // A is parent node;
	cout << '\n';
	postorder(0);
	cout << '\n';
	return 0;
}
