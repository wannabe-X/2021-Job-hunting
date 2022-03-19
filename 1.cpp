/*
 * @Description:
 * @Author: Mr. Lee
 * @Date: 2022-03-19 15:38:10
 * @LastEditTime: 2022-03-19 15:53:25
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int idx_x[] = {-1, 1, 0, 0}, idx_y[] = {0, 0, -1, 1};
int m, n;

void dfs(int x, int y, vector<vector<int>> &nums)
{
    nums[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int tmpx = x + idx_x[i], tmpy = y + idx_y[i];
        if (tmpx >= 0 && tmpx < m && tmpy >= 0 && tmpy < n && nums[tmpx][tmpy] == 1)
        {
            dfs(tmpx, tmpy, nums);
        }
    }
}

int func(vector<vector<int>> &nums)
{
    m = nums.size();
    n = nums[0].size();
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (nums[i][j] == 1)
            {
                ans++;
                dfs(i, j, nums);
            }
        }
    }
    return ans;
}

int main(int argc, char *argv[])
{
    vector<vector<int>> nums = {{0, 0, 0, 0, 1}, {0, 1, 1, 0, 0}, {0, 0, 0, 0, 0}, {0, 1, 1, 1, 0}, {0, 0, 0, 0, 1}};
    int res = func(nums);
    cout << res << endl;

    return 0;
}