#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int maxProfit(int k, vector<int> &prices)
{
    if (prices.size() == 0)
        return 0;

    int n = prices.size();
    int dp[n + 1][k + 1][2];
    memset(dp, 0x00, sizeof(dp));

    for (int i = 0; i <= n; i++)
    {
        for (int j = k; j >= 1; j--)
        {
            if (i == 0)
            {
                dp[i][j][1] = INT_MIN;
            }
            else
            {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i - 1]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i - 1]);
            }
        }
    }
    return dp[n][k][0];
}

int main()
{
    vector<int> prices = {2, 2, 6, 5, 0, 3, 6};
    int k = 3;
    int ans = maxProfit(k, prices);
    cout << ans << endl;
}