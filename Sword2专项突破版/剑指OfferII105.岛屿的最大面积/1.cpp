/*
 * @Description: 剑指 Offer II 105. 岛屿的最大面积
 * @Author: Mr. Lee
 * @Date: 2021-09-18 11:16:04
 * @LastEditTime: 2021-09-18 12:01:48
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tmp = 0;

void dfs(vector<vector<int>> &grid, int idx, int idy)
{
    if (idx < 0 || idy < 0 || idx > grid.size() - 1 || idy > grid[0].size() - 1 || grid[idx][idy] == 0)
        return;

    grid[idx][idy] = 0;
    tmp++;

    dfs(grid, idx + 1, idy);
    dfs(grid, idx - 1, idy);
    dfs(grid, idx, idy + 1);
    dfs(grid, idx, idy - 1);
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    int ans = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                dfs(grid, i, j);
                ans = max(ans, tmp);
                tmp = 0;
            }
        }
    }

    return ans;
}

int main(void)
{
    vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

    int ans = maxAreaOfIsland(grid);
    cout << ans << endl;

    return 0;
}