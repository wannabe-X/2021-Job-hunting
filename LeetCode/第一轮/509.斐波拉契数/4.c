#include<stdio.h>

// ½â·¨5 ×´Ì¬Ñ¹Ëõ
int fib(int n){
	if(n==0) return 0;
	if(n==1) return 1;
	
	int qian = 1, hou = 1, sum = 0, i;
	for(i=3;i<=n;i++)
	{
		sum = qian + hou;
		hou = qian;
		qian = sum;
	}
	
	return qian;
}

int main(void){
	int n;
	scanf("%d", &n);
	printf("%d", fib(n));
}
