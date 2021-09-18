/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-18 13:57:54
 * @LastEditTime: 2021-09-18 14:58:10
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int>> func(vector<vector<int>> &nums, int N, int M)
{
    vector<vector<int>> res(N, vector<int>(M, 0));
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < N * M; i++)
    {
        vector<int> tmp;
        for (int j = 1; j < 5; j++)
        {
            tmp.push_back(nums[i][j]);
        }
        m[nums[i][0]] = tmp;

        if (nums[i][1] == 0 && nums[i][2] == 0)
            res[0][0] = nums[i][0];
        if (nums[i][2] == 0 && nums[i][3] == 0)
            res[0][M - 1] = nums[i][0];
        if (nums[i][1] == 0 && nums[i][4] == 0)
            res[N - 1][0] = nums[i][0];
        if (nums[i][3] == 0 && nums[i][4] == 0)
            res[N - 1][M - 1] = nums[i][0];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (res[i][j])
            {
                if (i >= 0 && i < N && j - 1 >= 0 && j - 1 < M)
                    res[i][j - 1] = m[res[i][j]][0];
                if (i - 1 >= 0 && i < N && j >= 0 && j < M)
                    res[i - 1][j] = m[res[i][j]][1];
                if (i >= 0 && i < N && j + 1 >= 0 && j + 1 < M)
                    res[i][j + 1] = m[res[i][j]][2];
                if (i + 1 >= 0 && i + 1 < N && j >= 0 && j < M)
                    res[i + 1][j] = m[res[i][j]][3];
            }
        }
    }

    return res;
}

int main(void)
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> nums(N * M, vector<int>(5, 0));
    for (int i = 0; i < N * M; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> nums[i][j];
        }
    }

    vector<vector<int>> ans = func(nums, N, M);
    for (auto &x : ans)
    {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}