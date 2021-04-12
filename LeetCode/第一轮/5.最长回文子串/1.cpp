#include <iostream>
#include <vector>

using namespace std;

string longestPalindrome(string s)
{
    if(s.size()==1 || s.size()==2) return s.substr(0,1);

    int n = s.size();
    int k = n;
    int g, l, max1 = INT_MIN;

    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    while (k-- > 0)
    {
        for (int i = 0; i < k; i++)
        {
            int j = i + n - k;
            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);

            if (max1 < dp[i][j])
            {
                max1 = dp[i][j];
                g = i;
                l = j;
            }
        }
    }
    return s.substr(g, l - g + 1);
}



int main()
{
    string a = "acbccbbc";
    string max_ = longestPalindrome(a);
    cout << max_ << endl;
    return 0;
}
