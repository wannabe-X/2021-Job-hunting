/*
 * @Description: 剑指 Offer 63. 股票的最大利润
 * @Author: Mr. Lee
 * @Date: 2021-09-23 14:24:10
 * @LastEditTime: 2021-09-23 14:29:59
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int res = 0, tmp = INT_MAX;
    for (int i = 0; i < prices.size(); i++)
    {
        tmp = min(prices[i], tmp);
        res = max(res, max(prices[i] - tmp, 0));
    }

    return res;
}

int main(void)
{
    vector<int> prices = {7,6,4,3,1};
    int ans = maxProfit(prices);
    cout << ans << endl;

    return 0;
}