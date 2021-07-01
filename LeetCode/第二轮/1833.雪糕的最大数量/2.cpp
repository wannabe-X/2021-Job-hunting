/*
 * @Description: 1833. 雪糕的最大数量。01背包问题
 * @Author: Mr. Lee
 * @Date: 2021-07-02 00:19:36
 * @LastEditTime: 2021-07-02 00:44:30
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxIceCream(vector<int> &costs, int coins)
{
    vector<int> dp(coins + 1);

    for (int num : costs)
    {
        for (int j = coins; j >= num; j--)
        {
            dp[j] = max(dp[j], dp[j - num] + 1);
        }
    }

    return dp[coins];
}

int main()
{
    vector<int> costs = {1, 3, 2, 4, 1};
    int coins = 7;
    int ans = maxIceCream(costs, coins);
    cout << ans << endl;

    return 0;
}