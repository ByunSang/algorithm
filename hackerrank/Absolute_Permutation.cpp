#include <bits/stdc++.h>

using namespace std;

// Complete the absolutePermutation function below.
int main() {

    int t;
    cin>>t;
    
    while(t--){
        int n, k;
        scanf("%d %d", &n, &k);
        
        vector<int> arr;
        vector<bool> check(n);
        for(int i =1; i <= n+1; i++){
            
            if (i-k > 0 && !check[i-k-1] && i-k <= n){
                arr.push_back(i-k);
                check[i-k-1] = true;
            }
            else if (k+i > 0 && !check[k+i-1] && k+i <= n){
                arr.push_back(k+i);
                check[k+i-1] = true;
            }
            else {
                break;
            }
        }
        if (arr.size() == n){
            for (int i = 0; i<arr.size(); i++){
                printf("%d ",arr[i]);
            }
            printf("\n");
        } 
        else {
            printf("-1\n");  
        }
        
    }
}   
    
    


