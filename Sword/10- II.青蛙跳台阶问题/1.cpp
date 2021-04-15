#include <iostream>

using namespace std;
// 常见的递归法

// 假设已知第n-1级台阶的跳法，青蛙在n-1级台阶上时只有一种跳法（就是只迈一步）
// 所以青蛙在n-1n−1级台阶上时跳法为dp[n−1]∗1

// 青蛙还可以一次跳两阶，当已知n−2级的跳法时，青蛙在n−2级台阶上时也只有一种跳法
// （不能跳到n-1阶上，因为此种跳法已被包含在上面n-1的跳法当中），
// 青蛙在n-2级台阶上时增加新跳法为dp[i-2]*1种

int numWays(int n)
{
    if (n <= 1)
        return 1;
    return (numWays(n - 1) + numWays(n - 2)) % 1000000007;
}

int main(void)
{
    int n = 7;
    int ans = numWays(n);
    cout << ans << endl;
    return 0;
}