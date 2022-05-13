#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_SIZE 10002

int parent[MAX_SIZE];

struct Node
{
	int node_s;
	int node_e;
	int price;
};

bool compare(struct Node x, struct Node y)
{
	return x.price < y.price;
}

int find(int n)
{
	if (n == parent[n]) return n;

	return parent[n] = find(parent[n]);
}

int main ()
{
	int N, M =0;
	int res = 0;
	scanf("%d %d", &N, &M);

	vector<Node> v;
	
    for (int i = 1; i <= N; i++)
		parent[i] = i;
	
    for (int i = 0; i < M; i++ )
	{
		struct Node node;
		scanf("%d %d %d", &node.s, &node.e, &node.price);
		v.push_back(node);
	}
    
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < M; i++)
	{
		int s = find(v[i].node_s);
		int e = find(v[i].node_e);

		if (s == e) continue;

		parent[s] = e;
		res += v[i].price;
	}
	cout << res << endl;
    
    return 0;
}
