/*
 * @Description: 剑指 Offer II 013. 二维子矩阵的和
 * @Author: Mr. Lee
 * @Date: 2021-08-14 22:58:37
 * @LastEditTime: 2021-08-15 00:07:39
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

class NumMatrix
{
public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> tmp(m + 1, vector<int>(n + 1));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                tmp[i + 1][j + 1] = tmp[i][j + 1] + tmp[i + 1][j] - tmp[i][j] + matrix[i][j];
            }
        }

        swap(tmp, preSum);
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int ans = 0;
        ans += preSum[row2 + 1][col2 + 1] - preSum[row1][col2 + 1] - preSum[row2 + 1][col1] + preSum[row1][col1];
        return ans;
    }

private:
    vector<vector<int>> preSum;
};

int main()
{
    return 0;
}