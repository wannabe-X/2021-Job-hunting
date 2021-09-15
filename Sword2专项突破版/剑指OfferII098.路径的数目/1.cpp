/*
 * @Description: 剑指 Offer II 098. 路径的数目
 * @Author: Mr. Lee
 * @Date: 2021-09-14 23:05:02
 * @LastEditTime: 2021-09-14 23:22:15
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;
    for (int i = 1; i < m; i++)
        dp[i][0] += dp[i - 1][0];
    for (int i = 1; i < n; i++)
        dp[0][i] += dp[0][i - 1];

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
}

int main(void)
{
    int m = 3, n = 7;
    int ans = uniquePaths(m, n);
    cout << ans;
    
    return 0;
}