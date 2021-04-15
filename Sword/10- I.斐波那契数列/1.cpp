#include <iostream>

using namespace std;

// 常规递归解法
int fib(int n)
{
    if (n <= 1)
        return n;
    if (n == 2)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

int main(void)
{
    int n = 3;
    int ans = fib(n);
    cout << ans << endl;
    return 0;
}