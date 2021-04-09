#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the highestValuePalindrome function below.
int main() {
    string s;
    int n, k =0;
    int flag = 0;
    
    scanf("%d %d\n", &n, &k);
    cin >> s;
    string tmp = s;
    
    if(n == 1){
        if (k >= 1){
            printf("9\n");
        }
        else {
            printf("%c\n", s[0]);
        }
        return 0;
    }
    
    vector <int> index;
    int left = 0;
    int right = 0;
    int harf_size = n/2;
    if (n % 2 == 0){
        left = n/2 -1;
        right = n/2;
        //printf ("left :%d right: %d\n", left, right);
    }
    else {
        left = n/2 -1;
        right = n/2 +1;
        //printf ("left :%d right: %d\n", left, right);
    }
    for(int i =0; i<harf_size; i++){
        //cout << "i" << i <<endl;
        if(s[left] != s[right]){
            flag = 1;
            //printf("%c %c\n", s[left], s[right]);
            //index.insert(index.begin(), left);
            if(s[left] > s[right]){
                s[right] = s[left];
            }
            else {
                s[left] = s[right];
            }
            k--;
        }                
        left--; right++;
    }
    
    //cout << s << " " << k << endl;
    if (k == 0) {
        cout  << s <<endl;
        return 0;
    }
    if (k < 0) {
        printf ("-1\n");
        return 0;
    }
    
    int _left  =0;
    int _right =n-1;
    
    while(_left <= _right){
        if ((_left == _right) && k>0){
            s[_right] = '9';
        }  
        if (s[_left] != '9'){
            if (k >=2 && tmp[_left]==s[_left] && tmp[_right]==s[_right]){
                s[_left] = s[_right] = '9';
                k-=2;
            }
            //alread use k  example 4344  -> 4444
            //&& k >=1      example 4344  -> 4994
            //flag          example 12321 -> 12921 
            else if(k >=1 && (tmp[_left]!=s[_left] || tmp[right]!=s[_right]) && flag==1 ){
                s[_left] = s[_right] = '9';
                k--;
            }
        }
        _left++; _right--;
    }
    
    cout << s << endl;
    
    return 0;
}



