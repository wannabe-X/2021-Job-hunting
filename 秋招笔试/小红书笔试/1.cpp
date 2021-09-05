/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-04 09:57:14
 * @LastEditTime: 2021-09-04 10:41:02
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int func(vector<vector<int>> &nums)
{
    int res = nums[0][0];
    int sum[nums.size()], dp[nums.size()];

    for (int i = 0; i < nums.size(); i++)
    {
        memset(sum, 0, sizeof(sum));
        for (int j = i; j < nums.size(); j++)
        {
            for (int k = 0; k < nums.size(); k++)
            {
                sum[k] += nums[k][j];
            }

            dp[0] = sum[0];

            res = max(dp[0], res);

            for (int k = 1; k < nums.size(); k++)
            {
                dp[k] = max(sum[k], dp[k - 1] + sum[k]);
                res = max(dp[k], res);
            }
        }
    }

    return res;
}

int main(void)
{
    int n;
    cin >> n;

    vector<vector<int>> nums(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> nums[i][j];
    }

    int ans = func(nums);
    cout << ans;

    return 0;
}