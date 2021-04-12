#include <iostream>
#include <vector>

using namespace std;

bool stoneGame(vector<int> &piles)
{
    // �ⷨ1 dp[i][j]�е�Ԫ��ΪԪ�飬��ʾ��ʯ��[i..j]�����ֺͺ��ֵĵ÷�
    // int n = piles.size();
    // vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(n));

    // for (int i = 0; i < n; i++)
    // {
    //     dp[i][i].first = piles[i];
    //     dp[i][i].second = 0;
    // }

    // for (int l = 2; l <= n; l++)
    // {
    //     for (int i = 0; i <= n - l; i++)
    //     {
    //         int j = l + i - 1;
    // ����ѡ����ߵ�ʯ�ѣ���ôʣ�µľͽ�������[i+1..j]��ʯ���е�����
    //         int left = piles[i] + dp[i + 1][j].second;
    // ����ѡ���бߵ�ʯ�ѣ���ôʣ�µľͽ�������[i..j-1]��ʯ���е�����
    //         int right = piles[j] + dp[i][j - 1].second;
    // ����ѡ������ߵ�ʯ�ѣ���ô���־ͳ�Ϊ��[i+1..j]ʯ���е�����
    //         if (left > right)
    //         {
    //             dp[i][j].first = left;
    //             dp[i][j].second = dp[i + 1][j].first;
    //         }
    // ����ѡ�����ұߵ�ʯ�ѣ���ô���־ͳ�Ϊ��[i..j-1]ʯ���е�����
    //         else
    //         {
    //             dp[i][j].first = right;
    //             dp[i][j].second = dp[i][j - 1].first;
    //         }
    //     }
    // }

    // int res = dp[0][n - 1].first - dp[0][n - 1].second;
    // return res > 0;

    // �ⷨ2 dp[i][j]�ĺ����ǣ�ʯ��[i..j]��������ֵĵ÷�����
    // б�ű���
    // int n = piles.size(),k=n;
    // vector<vector<int>> dp(n,vector<int>(n,0));

    // for(int i=0;i<n;i++)
    //     dp[i][i]=piles[i];

    // while (k-- > 0)
    // {
    //     for (int i = 0; i < k; i++)
    //     {
    //         int j = i + n - k;     
    //         dp[i][j] = max(piles[i]-dp[i+1][j],piles[j]-dp[i][j-1]);

    //     }
    // }
    // return dp[0][n - 1];

    // �������
    int n = piles.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = piles[i];
    }

    for (int i = n - 2; i > -1; i--)
    {
        for (int j = i + 1; j < n; j++)
            dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
    }

    return dp[0][n - 1] > 0;
}

int main()
{
    vector<int> piles = {3, 9, 1, 2};
    bool ans = stoneGame(piles);
    cout << ans << endl;
}