#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    int dp_i10 = 0, dp_i11 = INT_MIN; // dp[i-1][1][0/1] ��ʼֵ
    int dp_i20 = 0, dp_i21 = INT_MIN; // dp[i-1][2][0/1]
    
    for (int i = 0; i < n; i++)
    {
        dp_i20 = max(dp_i20, dp_i21 + prices[i]);
        dp_i21 = max(dp_i21, dp_i10 - prices[i]);

        dp_i10 = max(dp_i10, dp_i11 + prices[i]);
        // ����֮ǰ������һ�� dp_i01��ԶΪ0��
        // dp[i-1][0][0] ǰһ�������0�ν��ף����ϲ����й�Ʊ������Ϊ0
        dp_i11 = max(dp_i11, -prices[i]);
    }
    return dp_i20;
}

int main()
{
    vector<int> prices = {2, 1, 2, 0, 1};
    int ans = maxProfit(prices);
    cout << ans << endl;
}