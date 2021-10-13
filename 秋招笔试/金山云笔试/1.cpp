/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-10-13 21:34:35
 * @LastEditTime: 2021-10-13 22:53:55
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int func(vector<vector<int>> nums)
{
    if (nums.size() == 0)
        return 0;

    int n = nums.size(), m = nums[n - 1].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = nums[0][0];
    int last_idx = 0;

    for (int i = 1; i < n; i++)
        dp[i][0] = dp[i - 1][0] + nums[i][0];

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < i + 1; j++)
        {
            int up = dp[i - 1][j], left = dp[i][j - 1];
            dp[i][j] = max(up, left) + nums[i][j];
        }
    }

    int res = INT8_MIN;
    for (int i = 0; i < m; i++)
    {
        res = max(res, dp[n - 2][i] + nums[n - 1][i]);
    }

    return res;
}

int main(void)
{
    int N;
    cin >> N;
    vector<vector<int>> nums;

    for (int i = 0; i < N; i++)
    {
        vector<int> tnum;
        for (int j = 0; j < i + 1; j++)
        {
            int tmp;
            cin >> tmp;
            tnum.push_back(tmp);
        }
        nums.push_back(tnum);
    }

    int ans = func(nums);
    cout << ans << endl;

    return 0;
}