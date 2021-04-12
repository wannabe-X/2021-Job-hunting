#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int dp_0 = 0, dp_1 = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        // 最低的时候买入，最高的时候卖出

        // 股票卖出的时候要求最大 利润最大
        dp_0 = max(dp_0, dp_1 + prices[i]);
        // 股票买入的时候要求最小 亏损最小
        dp_1 = max(dp_1, -prices[i]);
    }

    return dp_0;
}

int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    int ans = maxProfit(prices);
    cout << ans << endl;
}