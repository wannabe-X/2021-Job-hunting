/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-07 18:47:40
 * @LastEditTime: 2021-09-07 19:59:12
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> func(vector<vector<int>> &nums, int K)
{
    int N = nums.size();
    vector<vector<int>> res(N * K, vector<int>(N * K, 0));

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums[0].size(); j++)
        {
            int tmp1 = i * K, tmp2 = j * K;
            for (int m = tmp1; m < tmp1 + K; m++)
            {
                for (int n = tmp2; n < tmp2 + K; n++)
                    res[m][n] = nums[i][j];
            }
        }
    }

    return res;
}

int main(void)
{
    int N, K;
    cin >> N >> K;
    vector<vector<int>> nums(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> nums[i][j];
    }
    vector<vector<int>> ans = func(nums, K);

    for (auto &x : ans)
    {
        for (auto &y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}