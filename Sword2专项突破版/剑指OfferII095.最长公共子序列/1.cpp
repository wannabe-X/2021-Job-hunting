/*
 * @Description: 剑指 Offer II 095. 最长公共子序列
 * @Author: Mr. Lee
 * @Date: 2021-09-14 11:11:32
 * @LastEditTime: 2021-09-14 11:26:19
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestCommonSubsequence(string text1, string text2)
{
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    return dp[m][n];
}

int main(void)
{
    string text1 = "abcde", text2 = "ace";
    int ans = longestCommonSubsequence(text1, text2);
    cout << ans << endl;

    return 0;
}