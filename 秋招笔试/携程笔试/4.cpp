/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-10-13 16:21:25
 * @LastEditTime: 2021-10-13 16:33:10
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> func1(string s, int l, int r)
{
    while (l > -1 && r < s.size() && s[l] == s[r])
    {
        l--;
        r++;
    }

    return {l + 1, r - 1};
}

string func(string s)
{
    int res1 = 0, res2 = 0;
    for (int i = 0; i < s.size(); i++)
    {
        vector<int> tmp1 = func1(s, i, i);
        if (tmp1[1] - tmp1[0] > res2 - res1)
        {
            res2 = tmp1[1];
            res1 = tmp1[0];
        }

        tmp1 = func1(s, i, i + 1);
        if (tmp1[1] - tmp1[0] > res2 - res1)
        {
            res2 = tmp1[1];
            res1 = tmp1[0];
        }
    }

    return s.substr(res1, res2 - res1 + 1);
}

int main(void)
{
    string s;
    cin >> s;
    string ans = func(s);
    cout << ans << endl;

    return 0;
}