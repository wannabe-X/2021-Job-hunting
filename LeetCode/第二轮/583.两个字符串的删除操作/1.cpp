/*
 * @Description: 583. 两个字符串的删除操作
 * @Author: Mr. Lee
 * @Date: 2021-09-25 20:18:07
 * @LastEditTime: 2021-09-25 21:17:52
 * @LastEditors: Mr. Lee
 */

// 计算最长公共子序列即可
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minDistance(string word1, string word2)
{
    int n = word1.size(), m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        char c1 = word1[i - 1];
        for (int j = 1; j <= m; j++)
        {
            char c2 = word2[j - 1];
            if (c1 == c2)
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    int lcs = dp[n][m];

    return m + n - 2 * lcs;
}

int main(void)
{
    string s1 = "a", s2 = "c";
    int ans = minDistance(s1, s2);
    cout << ans << endl;

    return 0;
}