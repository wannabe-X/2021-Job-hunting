#include <iostream>

using namespace std;

// 迭代法
int fib(int n)
{
    if (n <= 1)
        return n;

    int val = 0;
    int first = 0, second = 1;
    for (int i = 2; i < n + 1; i++)
    {
        val = (second + first) % 1000000007;
        first = second;
        second = val;
    }

    return val;
}

int main(void)
{
    int n = 45;
    int ans = fib(n);
    cout << ans << endl;
    return 0;
}