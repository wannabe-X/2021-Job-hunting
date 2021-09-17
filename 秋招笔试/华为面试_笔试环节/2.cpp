/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-16 15:25:07
 * @LastEditTime: 2021-09-16 18:14:22
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<char>> &grid, int idx, int idy)
{
    if ((idx < 0 || idx > grid.size() - 1) || (idy < 0 || idy > grid[0].size() - 1) || grid[idx][idy] == '0')
        return;
    grid[idx][idy] = '0';
    dfs(grid, idx - 1, idy);
    dfs(grid, idx + 1, idy);
    dfs(grid, idx, idy - 1);
    dfs(grid, idx, idy + 1);
}
int func(vector<vector<char>> &grid)
{
    int m = grid.size();
    if (m == 0)
        return 0;
    int n = grid[0].size();
    int res = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '1')
            {
                res++;
                dfs(grid, i, j);
            }
        }
    }
    return res;
}

int main(void)
{
    // vector<vector<char>> grid = {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
    vector<vector<char>> grid = {{'1', '1', '0', '0', '0'}, {'1', '1', '0', '0', '0'}, 
                                {'0', '0', '1', '0', '0'}, {'0', '0', '0', '1', '1'}};
    int ans = func(grid);
    cout << ans << endl;

    return 0;
}