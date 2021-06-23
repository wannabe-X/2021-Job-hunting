/*
 * @Description: 机器人的运动范围。参考代码
 * @Author: Mr. Lee
 * @Date: 2021-06-23 14:16:20
 * @LastEditTime: 2021-06-23 17:22:11
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

int dfs(int i, int j, int si, int sj, vector<vector<bool>> &visited, int rows, int cols, int threshold)
{
    if (i >= rows || j >= cols || threshold < si + sj || visited[i][j])
        return 0;

    visited[i][j] = true;

    return 1 + dfs(i + 1, j, (i + 1) % 10 ? si + 1 : si - 8, sj, visited, rows, cols, threshold) // 向右运动
           + dfs(i, j + 1, si, (j + 1) % 10 ? sj + 1 : sj - 8, visited, rows, cols, threshold);  // 向下运动
}

int movingCount(int threshold, int rows, int cols)
{
    vector<vector<bool>> visited(rows, vector<bool>(cols, 0));
    return dfs(0, 0, 0, 0, visited, rows, cols, threshold);
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
