/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-14 19:51:53
 * @LastEditTime: 2021-09-14 21:17:20
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int func(string str)
{
    int categories, count = 0, res = 0;
    unordered_map<char, int> m;
    for (int i = 0; i < str.size(); i++)
    {
        m[str[i]]++;
        count++;
    }

    categories = count / m.size();

    for (auto it = m.begin(); it != m.end(); it++)
    {
        res += abs(categories - (*it).second);
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