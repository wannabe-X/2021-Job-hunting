/*
 * @Description: 剑指 Offer II 020. 回文子字符串的个数
 * @Author: Mr. Lee
 * @Date: 2021-08-19 00:09:07
 * @LastEditTime: 2021-08-19 00:43:15
 * @LastEditors: Mr. Lee
 */

// 动态规划法

#include <vector>
#include <iostream>

using namespace std;

int countSubstrings(string s)
{
    int res = 0, n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n));

    // 初始化，单个长度的子字符串可以构成回文
    // 同时也计算了长度为1的子字符串可以构成回文的方案数为n
    for (int i = 0; i < n; i++)
        dp[i][i] = true;

    // 接下来考察长度为2-n可以构成回文的子字符串的数量
    for (int len = 2; len <= n; len++)
    {
        for (int left = 0; left <= n - len; left++)
        {
            int right = left + len - 1;

            if (right == left + 1 && s[left] == s[right])
            {
                dp[left][right] = true;
                res++;
            }
            else if (s[left] == s[right] && dp[left + 1][right - 1])
            {
                dp[left][right] = true;
                res++;
            }
            else
                dp[left][right] = false;
        }
    }

    return res + n;
}

int main()
{
    string s = "aaa";
    int ans = countSubstrings(s);
    cout << ans << endl;

    return 0;
}