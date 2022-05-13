#include <iostream>
#include <vector>

using namespace std;

int ans;
int root;
int del;
vector<vector<int> > v;

/*int find(int D)
{
	v[D]  delete;
	for (int i = 0; i < v[D].size(); i ++)
		find(v[D].get(i));
	
	
}*/

int find(int node)
{	
	bool child = false;
	int cn = v[node].size();
	for (int i = 0; i < cn; i++)
	{
		int tmp = v[node][i];
		if (tmp == del) continue;
	
		find(tmp);
		child = true;
		
	}
	if (!child) ans++;

	return 0;
}

int main()
{
	int N;
	int tmp ;

	scanf("%d", &N);
	
	v = vector<vector<int> > (N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &tmp);
		if (tmp == -1) {
			root = i;
			continue;
		}
		v[tmp].push_back(i);
	}

	scanf("%d", &del);

	if (del == root ) printf("0\n");
	else {
		find(root);
		printf("%d\n", ans);
	}
	return 0;
}
