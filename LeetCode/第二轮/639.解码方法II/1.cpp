/*
 * @Description: 639. 解码方法 II
 * @Author: Mr. Lee
 * @Date: 2021-09-27 09:35:53
 * @LastEditTime: 2021-09-27 09:52:12
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int numDecodings(string s)
{
    int64_t dp[3] = {0}, half = 1, sum = 1;
    int mod = 1e9 + 7;
    for (char c : s)
    {
        if (c == '*')
        {
            half = dp[1] * 9 + dp[2] * 6;
            dp[0] = sum * 7;
            dp[1] = dp[2] = sum;
        }
        else
        {
            int x = c - '0';
            half = (x < 7) * dp[2] + dp[1];
            memset(dp, 0, sizeof(int64_t) * 3);
            dp[(x < 3) * x] = sum * !!x; //x为1,2时dp[x]=sum, x为3~9时dp[0]=sum, 为0时不变
        }
        sum = (dp[0] + dp[1] + dp[2] + half) % mod;
    }

    return sum;
}

int main(void)
{
    string s = "2*";
    int ans = numDecodings(s);
    cout << ans << endl;

    return 0;
}