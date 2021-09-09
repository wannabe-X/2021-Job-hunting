/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-09 18:57:24
 * @LastEditTime: 2021-09-09 22:17:32
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int func(string str, vector<pair<int, int>> &score, int n, int m)
{
    int res = 0;

    vector<int> dp(str.size() + 1);
    dp[0] = 0;
    for (int j = 1; j < n + 1; j++)
    {
        for (auto &sc : score)
        {
            if (j >= sc.first)
            {
                dp[j] = max(dp[j], dp[j - sc.first] + sc.second);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        while (i < n && str[i] == '1')
        {
            i++;
            count++;
        }

        res += dp[count];
    }

    return res;
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    string str;
    cin >> str;
    int tmp1, tmp2;
    vector<pair<int, int>> score;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp1 >> tmp2;
        score.push_back({tmp1, tmp2});
    }

    int ans = func(str, score, n, m);
    cout << ans;

    return 0;
}
