/*
 * @Description: 剑指 Offer II 100. 三角形中最小路径之和
 * @Author: Mr. Lee
 * @Date: 2021-09-15 11:17:54
 * @LastEditTime: 2021-09-15 14:39:33
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumTotal(vector<vector<int>> &triangle)
{
    int m = triangle.size(), n = triangle[m - 1].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = triangle[0][0];
    int res = INT_MAX;
    for (int i = 1; i < m; i++)
    {
        int len = triangle[i].size();
        for (int j = 0; j < len; j++)
        {
            if (j > 0 && j < len - 1)
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]);
            if (j == 0)
            {
                dp[i][j] = dp[i - 1][j];
            }
            if (j == len - 1)
                dp[i][j] = dp[i - 1][j - 1];

            dp[i][j] += triangle[i][j];

            if (i == m - 1)
                res = min(res, dp[m - 1][i]);
        }
    }

    return res;
}

// 优化方案
int minimumTotal(vector<vector<int>> &triangle)
{
    int m = triangle.size();
    if (m == 1)
        return triangle[0][0];

    int n = triangle[m - 1].size();
    vector<int> dp(n, 0);

    int res = INT_MAX;
    dp[0] = triangle[0][0];

    for (int i = 1; i < m; i++)
    {
        for (int j = i; j > -1; j--)
        {
            if (j == i)
            {
                dp[j] = dp[j - 1];
            }
            else if (j > 0)
                dp[j] = min(dp[j - 1], dp[j]);

            dp[j] += triangle[i][j];

            if (i == m - 1)
                res = min(res, dp[j]);
        }
    }

    return res;
}

int main(void)
{
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    int ans = minimumTotal(triangle);
    cout << ans << endl;

    return 0;
}

