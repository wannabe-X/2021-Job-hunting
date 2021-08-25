/*
 * @Description: 剑指 Offer II 015. 字符串中的所有变位词
 * @Author: Mr. Lee
 * @Date: 2021-08-16 21:57:02
 * @LastEditTime: 2021-08-19 11:05:43
 * @LastEditors: Mr. Lee
 */

// 滑动窗口
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> findAnagrams(string s, string p)
{
    if (s.size() < p.size())
        return {};
        
    vector<int> res;
    vector<int> vs(26, 0), vp(26, 0);

    for (int i = 0; i < p.size(); i++)
    {
        vs[s[i] - 'a']++;
        vp[p[i] - 'a']++;
    }

    int left = 0, right = p.size();

    while (right < s.size())
    {
        if (vs == vp)
        {
            res.push_back(left);
        }

        vs[s[right++] - 'a']++;
        vs[s[left++] - 'a']--;
    }

    if (vs == vp)
    {
        res.push_back(left);
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