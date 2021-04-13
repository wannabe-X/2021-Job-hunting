#include<iostream>
# include<vector>

using namespace std;

// 解法4 自底向上的方法
int fib(int n){
	if(n==0) return 0;
	if(n==1) return 1;
	vector<int> dp(n+1, 0);
	
	dp[1] = dp[2] = 1;
	for(int i=3; i<=n;i++) dp[i] = dp[i-1] + dp[i-2];
	
	return dp[n];
}

int main(void){
	int n;
	cin >> n;
	cout << fib(n);
}
