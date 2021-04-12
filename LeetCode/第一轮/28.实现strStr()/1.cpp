#include <iostream>
#include <vector>

using namespace std;

// KMP 算法 haystack是文本串，needle是模式串
int strStr(string haystack, string needle)
{
    if (needle.size() == 0)
        return 0;
    int n = needle.size();
    vector<vector<int>> dp(n, vector<int>(256, 0));

    dp[0][needle.at(0) - '0'] = 1;

    int X = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 256; j++)
            dp[i][j] = dp[X][j];

        dp[i][needle.at(i) - '0'] = i + 1;
        X = dp[X][needle.at(i) - '0'];
    }

    int m = haystack.size();

    int k = 0;
    for (int i = 0; i < m; i++)
    {
        k = dp[k][haystack.at(i) - '0'];

        if (k == n)
            return i - n + 1;
    }

    return -1;
}

int main()
{
    string txt = "ababceee", pat = "eee";
    int ans = strStr(txt, pat);
    cout << ans << endl;
}