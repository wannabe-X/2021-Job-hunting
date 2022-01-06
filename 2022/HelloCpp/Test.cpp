#include<functional>

// function
int funA(int a, int b)
{
	printf("funA()\n");
	return 0;
}

// lambda 匿名函数


int main()
{
	//funA(5, 6);
	//std::function<int(int, int)> call = funA;
	//int n = call(5, 6);

	std::function<int(int, int)> call;
	int n = 5;
	// 匿名函数
	call = [n/*外部变量捕获列表*/](/*函数参数列表*/ int a, int b) -> int // 返回值类型
	{
		// 函数体
		printf("funB:%d\n", n + a + b);
		return a + b;
	};

	int ans = call(6, 7);
	printf("%d", ans);

	return 0;
}