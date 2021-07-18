/*
 * @Description: 5. 最长回文子串
 * @Author: Mr. Lee
 * @Date: 2021-07-18 14:14:48
 * @LastEditTime: 2021-07-18 15:12:45
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

string longestPalindrome(string s)
{
    int n = s.size();
    if (n <= 1)
        return s;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int maxlen = 1, begin = 0;

    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    for (int L = 2; L <= n; L++)
    {
        for (int i = 0; i < n; i++)
        {
            int j = L + i - 1;
            if (j >= n)
                break;

            if (s[i] != s[j])
            {
                dp[i][j] = 0;
            }
            else
            {
                if (L > 2)
                    dp[i][j] = dp[i + 1][j - 1];
                else
                    dp[i][j] = 1;
            }

            if (dp[i][j] && L > maxlen)
            {
                maxlen = L;
                begin = i;
            }
        }
    }

    return s.substr(begin, maxlen);
}

int main()
{
    string s = "ac";
    string ans = longestPalindrome(s);
    cout << ans << endl;

    return 0;
}
