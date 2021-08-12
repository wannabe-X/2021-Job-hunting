/*
 * @Description: 516. 最长回文子序列
 * @Author: Mr. Lee
 * @Date: 2021-08-12 18:51:29
 * @LastEditTime: 2021-08-12 23:07:56
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>

using namespace std;

int longestPalindromeSubseq(string s)
{
    int res = 0, n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 1; i > -1; i--)
    {
        dp[i][i] = 1;
        char c1 = s[i];
        for (int j = i + 1; j < n; j++)
        {
            char c2 = s[j];
            if (c1 == c2)
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }

    return dp[0][n - 1];
}

int main()
{
    string s = "bbbab";
    int ans = longestPalindromeSubseq(s);
    cout << ans << endl;

    return 0;
}