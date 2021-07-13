/*
 * @Description: 200. 岛屿数量
 * @Author: Mr. Lee
 * @Date: 2021-07-13 11:07:10
 * @LastEditTime: 2021-07-13 17:49:38
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

int numIslands(vector<vector<char>> &grid)
{
    int count = 0;

    return count;
}

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};
    int ans = numIslands(grid);
    cout << ans << endl;

    return 0;
}