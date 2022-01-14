/*
 * @Description: 1576. 替换所有的问号
 * @Author: Mr. Lee
 * @Date: 2022-01-05 22:40:43
 * @LastEditTime: 2022-01-05 22:46:49
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string modifyString(string s)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '?')
        {
            for (char c = 'a'; c < 'd'; c++)
            {
                if ((i > 0 && s[i - 1] == c) || (i < n - 1 && s[i + 1] == c))
                    continue;
                s[i] = c;
                break;
            }
        }
    }

    return s;
}

int main(int argc, char *argv[])
{
    string s = "j?qg??b";
    string ans = modifyString(s);
    cout << ans << endl;

    return 0;
}