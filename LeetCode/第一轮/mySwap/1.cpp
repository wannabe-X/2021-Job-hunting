#include <iostream>
using namespace std;
 
// �������mySwap���������Ͷ���
// void mySwap(int a, int b)
// {
// 	int temp = a;
// 	a = b;
// 	b = temp;
// }

// void mySwap(int *a, int *b)
// {
// 	int *temp = a;
// 	a = b;
// 	b = temp;

//     cout << *a << *b << endl;
// }

void mySwap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// void mySwap(int &a, int &b)
// {
// 	int temp = a;
// 	a = b;
// 	b = temp;
// }
 
int main()
{
	int n = 15, m = 20;
	cout << "before:\tn = " << n << ", \tm = " << m << endl;
	// ����Ǵ�ָ���������ַ�ʽ���ã�
	// mySwap(&n, &m);
	mySwap(&n, &m);
	cout << "after:\tn = " << n << ", \tm = " << m << endl;
 
	return 0;
}