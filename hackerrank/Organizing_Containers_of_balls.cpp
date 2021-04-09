#include <bits/stdc++.h>

using namespace std;
typedef unsigned int uint;

// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> container) {

    int size = container.size();
    vector<uint> ball_total(size, 0);
    vector<uint> container_total(size, 0);
     
    for(int i = 0; i < size; i++){
        for(int j = 0; j < container[i].size(); j++){
            container_total[i] += (uint)container[i][j];
            ball_total[j] += (uint)container[i][j]; 
        }
    }
    
    vector<uint>::iterator it;
    for (int i = 0; i < size; i++){
        it = find(container_total.begin(),container_total.end(),ball_total[i]);
        if (it == container_total.end()) return "Impossible";
        container_total.erase(it);
    }
    return "Possible";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}


