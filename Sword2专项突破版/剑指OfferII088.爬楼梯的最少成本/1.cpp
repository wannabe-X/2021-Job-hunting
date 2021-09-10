/*
 * @Description: 剑指 Offer II 088. 爬楼梯的最少成本
 * @Author: Mr. Lee
 * @Date: 2021-09-10 11:43:28
 * @LastEditTime: 2021-09-10 15:11:04
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();

    vector<int> dp(n + 1);

    for (int i = 2; i <= n; i++)
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);

    return dp[n];
}

int main(void)
{
    vector<int> cost = {10,15,20};
    int ans = minCostClimbingStairs(cost);
    cout << ans << endl;

    return 0;
}