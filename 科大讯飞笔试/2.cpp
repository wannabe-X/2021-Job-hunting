/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-08-15 18:53:43
 * @LastEditTime: 2021-08-15 21:09:45
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int findInterval(string str)
{
    int start = 0, t = 0;
    int ans = 1e5 + 5;
    int cnt[30];
    memset(cnt, 0, sizeof(cnt));

    for (int i = 0; i < str.size(); i++)
    {
        int c = str[i] - 'a';
        if (c == int('?' - '0'))
        {
            t++;
            continue;
        }
        else
        {
            if (!cnt[c])
                t++;
        }

        cnt[c]++;

        while (cnt[str[start] - 'a'] > 1)
        {
            cnt[str[start] - 'a']--;
            start++;
        }

        if (t == 26)
            ans = min(ans, i - start + 1);
    }

    return t < 26 ? -1 : ans;
}

int main()
{
    string str = "abcdefghijklmnopqrstuvw???xyz";
    int ans = findInterval(str);
    cout << ans << endl;

    return 0;
}
