/*
 * @Description: 机器人的运动范围。
 * @Author: Mr. Lee
 * @Date: 2021-06-23 14:16:20
 * @LastEditTime: 2021-06-23 17:21:53
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

int check(int x, int y)
{
    int sum = 0;
    while (x || y)
    {
        sum += (x % 10 + y % 10);
        x = (x / 10) ? x / 10 : 0;
        y = (y / 10) ? y / 10 : 0;
    }
    return sum;
}

int dfs(int x, int y, vector<vector<int>> &visited, int threshold, int rows, int cols)
{
    if (x >= rows || y >= cols || visited[x][y] || check(x, y) > threshold)
        return 0;

    visited[x][y] = 1;

    return 1 + dfs(x + 1, y, visited, threshold, rows, cols) // 向右走，递归
           + dfs(x, y + 1, visited, threshold, rows, cols);  // 向下走，递归
}

int movingCount(int threshold, int rows, int cols)
{
    vector<vector<int>> visited(rows, vector<int>(cols, 0));
    return dfs(0, 0, visited, threshold, rows, cols);
}

int main()
{
    // 测试用例
    // int threshold = 17, rows = 2, cols = 3;
    
    // 实际输入
    int threshold, rows, cols;
    cin >> threshold >> rows >> cols;
    int ans = movingCount(threshold, rows, cols);
    cout << ans << endl;

    return 0;
}
