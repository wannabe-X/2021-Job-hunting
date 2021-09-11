/*
 * @Description: 600. 不含连续1的非负整数
 * @Author: Mr. Lee
 * @Date: 2021-09-11 00:05:28
 * @LastEditTime: 2021-09-11 00:18:54
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 动态规划,参考代码
int findIntegers(int n)
{
    vector<int> dp(31);
    dp[0] = dp[1] = 1;
    for (int i = 2; i < 31; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int pre = 0, res = 0;
    for (int i = 29; i >= 0; --i)
    {
        int val = 1 << i;
        if ((n & val) != 0)
        {
            n -= val;
            res += dp[i + 1];
            if (pre == 1)
            {
                break;
            }
            pre = 1;
        }
        else
        {
            pre = 0;
        }

        if (i == 0)
        {
            ++res;
        }
    }

    return res;
}

int main(void)
{
    int n = 1e9;
    int ans = findIntegers(n);
    cout << ans;

    return 0;
}

