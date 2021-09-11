/*
 * @Description: 剑指 Offer II 091. 粉刷房子
 * @Author: Mr. Lee
 * @Date: 2021-09-10 22:34:13
 * @LastEditTime: 2021-09-12 00:02:21
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 贪心无法得到全局最优解
// int minValIdx(vector<int> nums)
// {
//     int idx = 0;
//     for (int i = 1; i < nums.size(); i++)
//     {
//         if (nums[i] < nums[idx])
//         {
//             idx = i;
//         }
//     }

//     return idx;
// }

// int minCost(vector<vector<int>> &costs)
// {
//     int n = costs.size();
//     int idx = minValIdx(costs[0]);
//     int res = costs[0][idx];

//     for (int i = 1; i < n; i++)
//     {
//         vector<int> v = costs[i];
//         int tmp = minValIdx(v);
//         if (idx == tmp)
//         {
//             v.erase(v.begin() + tmp);
//             tmp = minValIdx(v);
//         }
//         res += v[tmp];
//         idx = tmp;
//     }

//     return res;
// }

// 动态规划方法
int minCost(vector<vector<int>> &costs)
{
    int n = costs.size();
    vector<vector<int>> dp(n, vector<int>(3, 0));
    dp[0][0] = costs[0][0], dp[0][1] = costs[0][1], dp[0][2] = costs[0][2];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2];
    }

    return min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
}

int main(void)
{
    vector<vector<int>> costs = {{3, 5, 3}, {6, 17, 6}, {7, 13, 18}, {9, 10, 18}};
    int ans = minCost(costs);
    cout << ans;

    return 0;
}