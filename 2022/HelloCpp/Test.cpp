#include<functional>

// function
int funA(int a, int b)
{
	printf("funA()\n");
	return 0;
}

// lambda ��������


int main()
{
	//funA(5, 6);
	//std::function<int(int, int)> call = funA;
	//int n = call(5, 6);

	std::function<int(int, int)> call;
	int n = 5;
	// ��������
	call = [n/*�ⲿ���������б�*/](/*���������б�*/ int a, int b) -> int // ����ֵ����
	{
		// ������
		printf("funB:%d\n", n + a + b);
		return a + b;
	};

	int ans = call(6, 7);
	printf("%d", ans);

	return 0;
}