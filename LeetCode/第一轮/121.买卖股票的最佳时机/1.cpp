#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int dp_0 = 0, dp_1 = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        // ��͵�ʱ�����룬��ߵ�ʱ������

        // ��Ʊ������ʱ��Ҫ����� �������
        dp_0 = max(dp_0, dp_1 + prices[i]);
        // ��Ʊ�����ʱ��Ҫ����С ������С
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