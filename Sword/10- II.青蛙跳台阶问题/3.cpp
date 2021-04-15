#include <iostream>

using namespace std;

// 迭代法
int numWays(int n)
{
    if (n <= 1)
        return 1;

    int val = 1;
    int first = 1, second = 1;
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
    int n = 2;
    int ans = numWays(n);
    cout << ans << endl;
    return 0;
}