#include <bits/stdc++.h>

using namespace std;
    
vector<int> data;
vector<vector<int> > edges;
vector<bool> visit;
vector<int> sum;
int N;


/*
 * Complete the 'cutTheTree' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY data
 *  2. 2D_INTEGER_ARRAY edges
 */

int dfs(int node){
    int i = 0;
    int cn = edges[node].size();
    int ret = 0;
    //cout << "cn " << cn;
    //if (node == 0) return 0;
    
    visit[node] = true;
    
    //cout << "node: "<< node <<endl;
    
    for(i = 0; i < cn; i++){
        //cout << "edges[node][i]: " << node << i;
        int next = edges[node][i];
        //cout << next << endl;
        if(!visit[next]) 
            ret += dfs(next);
    }
    
    return sum[node] = data[node] +ret;
}

int main()
{   
    cin >> N;
    int total = 0;
    data.resize(N+1);
    //edges = vector<vector<int> > (N+1);
    //edges.resize(N+1, vector<int>(N+1, 0));
    edges.resize(N+1);
    visit.resize(N+1, false);
    sum.resize(N+1);

    for(int i =1; i <= N; i++){
        cin >> data[i];
        total += data[i];
    }
    
    for(int i = 0; i < N-1; i++){
        int u,v ;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u); 
        //cout << u << v << edges[u][v] << endl;
    }

    dfs(1); // 1 always root
    int MIN = INFINITY;
    for(int i = 1; i <= N; i++){
        MIN = MIN > (abs(total - sum[i] - sum[i])) ? (abs(total - sum[i] - sum[i])) : MIN;
    }
    cout << MIN << endl;
    
    
    return 0;
}

