/*
 * @Description: 451. 根据字符出现频率排序
 * @Author: Mr. Lee
 * @Date: 2021-07-03 12:28:06
 * @LastEditTime: 2021-07-03 14:30:59
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// bool cmp(const pair<char, int> &a, const pair<char, int> &b)
// {
//     return a.second > b.second;
// }

string frequencySort(string s)
{
    map<char, int> m;
    vector<pair<char, int>> v;
    for (auto &c : s)
        m[c]++;
    for (auto &x : m)
        v.push_back(x);
    // 按照字符出现的顺序排序
    // sort(v.begin(), v.end(), cmp);
    sort(v.begin(), v.end(), [](const pair<char, int> &a, const pair<char, int> &b)
         { return a.second > b.second; });

    string res;
    for (auto it = v.begin(); it != v.end(); it++)
    {
        for (int i = 0; i < (*it).second; res += (*it).first, i++)
            ;
    }

    return res;
}

int main()
{
    string s = "tree";
    string ans = frequencySort(s);
    cout << ans << endl;

    return 0;
}
