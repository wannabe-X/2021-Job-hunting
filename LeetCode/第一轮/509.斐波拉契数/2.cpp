#include<iostream>
#include<vector>

using namespace std;

// 解法3 带有备忘录的递归
int memorandum(vector<int> &memo, int n){
	if(n<=2) return 1;
	// 剪枝 避免重复运算，降低时间复杂度
	if(memo[n] != 0) return memo[n];
	// 递归计算斐波拉契数列
	memo[n] = memorandum(memo, n-1) + memorandum(memo, n-2);
	return memo[n];
}

int fib(int n){
	if(n==0) return 0;
	std::vector<int> memo(n+1, 0);

	return memorandum(memo, n);
}

int main(void){
	int n;
	scanf("%d",&n);
	printf("%d",fib(n));
}
