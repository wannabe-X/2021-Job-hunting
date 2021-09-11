/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-11 15:58:51
 * @LastEditTime: 2021-09-11 17:41:23
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isDivisible(string &str)
{
    int n = str.size();

    int odd = 0, even = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            odd += (str[i] - '0');
        else
            even += (str[i] - '0');
    }

    if (abs(odd - even) % 11 == 0 && (str[n - 1] - '0') % 2 == 0)
        return true;

    return true;
}

int func(string &str)
{
    int res = 0;
    for (int i = 0; i < str.size(); i++)
    {
        for (int j = 1; j < str.size() - i + 1; j++)
        {
            string tmp = str.substr(i, j);
            if (isDivisible(tmp))
                res++;
        }
    }

    return res;
}

int main(void)
{
    string str;
    cin >> str;
    int ans = func(str);
    cout << ans;

    return 0;
}