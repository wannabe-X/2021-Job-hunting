#include <iostream>
#include <vector>

using namespace std;

bool stoneGame(vector<int> &piles)
{
    // 解法1 dp[i][j]中的元素为元组，表示从石堆[i..j]的先手和后手的得分
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
    // 先手选择左边的石堆，那么剩下的就将会是在[i+1..j]的石堆中当后手
    //         int left = piles[i] + dp[i + 1][j].second;
    // 先手选择有边的石堆，那么剩下的就将会是在[i..j-1]的石堆中当后手
    //         int right = piles[j] + dp[i][j - 1].second;
    // 先手选择了左边的石堆，那么后手就成为了[i+1..j]石堆中的先手
    //         if (left > right)
    //         {
    //             dp[i][j].first = left;
    //             dp[i][j].second = dp[i + 1][j].first;
    //         }
    // 先手选择了右边的石堆，那么后手就成为了[i..j-1]石堆中的先手
    //         else
    //         {
    //             dp[i][j].first = right;
    //             dp[i][j].second = dp[i][j - 1].first;
    //         }
    //     }
    // }

    // int res = dp[0][n - 1].first - dp[0][n - 1].second;
    // return res > 0;

    // 解法2 dp[i][j]的含义是，石堆[i..j]先手与后手的得分最大差
    // 斜着遍历
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

    // 反向遍历
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