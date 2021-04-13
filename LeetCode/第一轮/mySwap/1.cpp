#include <iostream>
using namespace std;
 
// 这里插入mySwap函数声明和定义
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
	// 如果是传指针请用这种方式调用：
	// mySwap(&n, &m);
	mySwap(&n, &m);
	cout << "after:\tn = " << n << ", \tm = " << m << endl;
 
	return 0;
}