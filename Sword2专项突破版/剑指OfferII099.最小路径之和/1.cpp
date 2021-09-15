/*
 * @Description: 剑指 Offer II 099. 最小路径之和
 * @Author: Mr. Lee
 * @Date: 2021-09-14 22:22:20
 * @LastEditTime: 2021-09-14 22:37:59
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minPathSum(vector<vector<int>> &grid)
{
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
    dp[0][0] = grid[0][0];

    for (int i = 1; i < grid.size(); i++)
    {
        dp[i][0] += dp[i - 1][0] + grid[i][0];
    }

    for (int j = 1; j < grid[0].size(); j++)
    {
        dp[0][j] += dp[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < grid.size(); i++)
    {
        for (int j = 1; j < grid[0].size(); j++)
        {
            int up = dp[i - 1][j];
            int left = dp[i][j - 1];

            dp[i][j] = min(left, up) + grid[i][j];
        }
    }

    return dp[grid.size() - 1][grid[0].size() - 1];
}

int main(void)
{
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int ans = minPathSum(grid);
    cout << ans << endl;

    return 0;
}