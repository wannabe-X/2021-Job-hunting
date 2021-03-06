#include <iostream>
#include <vector>

using namespace std;

int longestPalindromeSubseq(string s)
{
    int n = s.size();
    int k = n;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    // for (int i = n - 2; i > -1; i--)
    // {
    //     for (int j = i + 1; j < n; j++)
    //         if (s[i] == s[j])
    //             dp[i][j] = dp[i + 1][j - 1] + 2;
    //         else
    //             dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
    // }

    while (k-- > 0)
    {
        for (int i = 0; i < k; i++)
        {
            int j = i + n - k;
            // cout << i<<j << endl;
            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return dp[0][n - 1];
}

int main()
{
    string a = "bbbab";
    int max_ = longestPalindromeSubseq(a);
    cout << max_ << endl;
    return 0;
}
