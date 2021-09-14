/*
 * @Description: 剑指 Offer II 092. 翻转字符
 * @Author: Mr. Lee
 * @Date: 2021-09-14 10:32:03
 * @LastEditTime: 2021-09-14 10:46:16
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minFlipsMonoIncr(string s)
{
    int n = s.size();
    vector<vector<int>> dp(2, vector<int>(2, 0));

    s[0] == '0' ? dp[0][1] = 1 : dp[0][0] = 1;

    for (int i = 1; i < n; i++)
    {
        dp[i % 2][0] = dp[(i - 1) % 2][0] + (s[i] != '0');
        dp[i % 2][1] = min(dp[(i - 1) % 2][0], dp[(i - 1) % 2][1]) + (s[i] != '1');
    }

    return min(dp[(n - 1) % 2][0], dp[(n - 1) % 2][1]);
}

int main(void)
{
    string s = "00110";
    int ans = minFlipsMonoIncr(s);
    cout << ans << endl;

    return 0;
}