/*
 * @Description: 顺时针打印矩阵
 * @Author: Mr. Lee
 * @Date: 2021-06-30 22:41:33
 * @LastEditTime: 2021-06-30 23:50:04
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> printMatrix(vector<vector<int>> &matrix)
{
    vector<int> res;
    if (matrix.empty())
        return res;

    int right = matrix[0].size() - 1, bottom = matrix.size() - 1, left = 0, top = 0;

    while (1)
    {
        // 从左向右走
        for (int i = left; i <= right; i++)
            res.push_back(matrix[top][i]);
        if (++top > bottom)
            break;

        // 从上向下走
        for (int i = top; i <= bottom; i++)
            res.push_back(matrix[i][right]);
        if (--right < left)
            break;

        // 从右向左走
        for (int i = right; i >= left; i--)
            res.push_back(matrix[bottom][i]);
        if (--bottom < top)
            break;

        // 从下向上走
        for (int i = bottom; i >= top; i--)
            res.push_back(matrix[i][left]);
        if (++left > right)
            break;
    }

    return res;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4},
                                  {5, 6, 7, 8},
                                  {9, 10, 11, 12},
                                  {13, 14, 15, 16}};
    vector<int> ans = printMatrix(matrix);
    for (int num : ans)
    {
        cout << num << " ";
    }

    return 0;
}
