#include <bits/stdc++.h>

using namespace std;

// Complete the happyLadybugs function below.
string happyLadybugs(string b) {
    vector <int> alpha(26,0);
    int available = 0;
    
    for(int i = 0; i < b.size(); i++){
        if (b[i]== '_') available = 1;
        if (b[i] >='A' && b[i] <= 'Z'){
            alpha[b[i]-'A'] ++;
        }
    }
    
    if(!available){
        if(b.size()%2 == 0){
            for(int i =0; i< b.size(); i=i+2){
                if(b[i]!=b[i+1]) return "NO";
            }
            
        }
        else {
            int cnt = 0;
            if(b.size() == 1) return "NO";
            
            for (int i = 0; i<b.size(); i++){
                if (b[i]==b[i+1] || b[i]==b[i-1]) cnt++;
            }
            if (cnt == b.size()) return "YES";
            else return "NO";
        }        
        return "YES";
    }
    else {
        for(int i =0; i< alpha.size(); i++){
            if (alpha[i] == 1){
               return "NO";
            }
            if(alpha[i] == b.size()) {   
                return "YES";
            }
        }
        return "YES";
    }

    return "NO";
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int g;
    cin >> g;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int g_itr = 0; g_itr < g; g_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}


