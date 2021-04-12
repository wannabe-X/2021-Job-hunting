#include<iostream>
#include<vector>

using namespace std;

// �ⷨ3 ���б���¼�ĵݹ�
int memorandum(vector<int> &memo, int n){
	if(n<=2) return 1;
	// ��֦ �����ظ����㣬����ʱ�临�Ӷ�
	if(memo[n] != 0) return memo[n];
	// �ݹ����쳲���������
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
