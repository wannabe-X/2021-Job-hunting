#include<stdio.h>

// �ⷨ1 �ݹ�
//int fib(int n){
//	if(n==0 || n==1) return n;
//	return fib(n-1) + fib(n-2);
//}

// �ⷨ2 ����������ʱ�临�Ӷ�
int fib(int N){
    if(N==0||N==1) return N;
    int a=0,b=1,i;
    for(i=2;i<=N;i++){
        b=a+b;
        a=b-a;
    }
    return b;
}

int main(void){
	int n;
	scanf("%d",&n);
	printf("%d",fib(n));
}
