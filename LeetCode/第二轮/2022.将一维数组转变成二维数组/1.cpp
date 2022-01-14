/*
 * @Description: 2022. 将一维数组转变成二维数组
 * @Author: Mr. Lee
 * @Date: 2022-01-01 12:17:44
 * @LastEditTime: 2022-01-01 12:27:36
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
{
    if (original.size() != m * n)
        return {};
    vector<vector<int>> res;
    for (int i = 0; i < m; i++)
    {
        auto idx = original.begin() + i * n;
        vector<int> tmp(idx, idx + n);
        res.push_back(tmp);
    }

    return res;
}

int main(int argc, char *argv[])
{
    vector<int> original = {1, 2, 3, 4};
    int m = 2, n = 2;

    return 0;
}