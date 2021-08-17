/*
 * @Description: 剑指 Offer II 015. 字符串中的所有变位词
 * @Author: Mr. Lee
 * @Date: 2021-08-16 21:57:02
 * @LastEditTime: 2021-08-16 22:03:15
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> findAnagrams(string s, string p)
{
    vector<int> res;
    sort(p.begin(), p.end());
    for (int i = 0; i < int(s.size() - p.size() + 1); i++)
    {
        string tmp = s.substr(i, p.size());
        sort(tmp.begin(), tmp.end());
        if (tmp == p)
        {
            res.push_back(i);
        }
    }

    return res;
}

int main()
{
    string s = "cbaebabacd", p = "abc";
    vector<int> ans = findAnagrams(s, p);
    for (auto &x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}