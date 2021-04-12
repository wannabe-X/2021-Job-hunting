#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    int dp_0 = 0, dp_1 = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int temp = dp_0;
        dp_0 = max(dp_0, dp_1 + prices[i]);
        dp_1 = max(dp_1, temp - prices[i] - fee);
    }

    return dp_0;
}

int main()
{
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    int ans = maxProfit(prices, fee);
    cout << ans << endl;
}