/*
 * @Description: 剑指 Offer II 103. 最少的硬币数目
 * @Author: Mr. Lee
 * @Date: 2021-09-15 15:02:01
 * @LastEditTime: 2021-09-15 15:46:30
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 动态规划 完全背包问题
int coinChange(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        for (auto &coin : coins)
        {
            if (i >= coin)
                dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }

    return dp[amount] == amount + 1 ? -1 : dp[amount];
}

int main(void)
{
    vector<int> coins = {2};
    int amount = 3;
    int ans = coinChange(coins, amount);
    cout << ans << endl;

    return 0;
}
