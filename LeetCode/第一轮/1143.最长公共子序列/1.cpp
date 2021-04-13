#include <iostream>
#include <vector>

using namespace std;

int longestCommonSubsequence(string text1, string text2)
{
    int m = text1.size(), n = text2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            // 因为i,j都是从1开始的，所以text1[i - 1]，text2[j - 1]比较的就是第i,j个元素
            dp[i][j] = (text1[i - 1] == text2[j - 1]) ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
    }

    return dp[m][n];
}

int main()
{
    string s1 = "ac", s2 = "babc";
    int ans = longestCommonSubsequence(s1, s2);
    cout << ans << endl;
    return 0;
}
