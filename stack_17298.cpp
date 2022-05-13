#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
using namespace std;
int main()
{
	int N;
	int arr[1000001];
	int ans[1000001];
	stack<int> stack;

	//scanf("%d", &N);
	cin >> N;
	
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	
	for(int i = N-1; i >= 0; i--){
		while(!stack.empty() && arr[i] >= stack.top()) stack.pop(); 
		
		if(stack.empty()) ans[i] = -1;
		else ans[i] = stack.top();

		stack.push(arr[i]);

	}

	for(int i = 0; i < N; i++)
		printf("%d ", ans[i]);

	return 0;
}
