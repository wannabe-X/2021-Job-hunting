/*
 * @Description: 剑指 Offer II 005. 单词长度的最大乘积
 * @Author: Mr. Lee
 * @Date: 2021-08-12 15:50:13
 * @LastEditTime: 2021-08-12 16:33:25
 * @LastEditors: Mr. Lee
 */

// 暴力破解 超时的解法
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool search(string &a, string &b)
{
    unordered_set<char> s;
    for (int i = 0; i < a.size(); i++)
        s.insert(a[i]);
    for (int i = 0; i < b.size(); i++)
    {
        if (s.count(b[i]))
            return false;
    }

    return true;
}

int maxProduct(vector<string> &words)
{
    int res = 0;
    for (int i = 0; i < words.size(); i++)
    {
        for (int j = i; j < words.size(); j++)
        {
            if (search(words[i], words[j]))
                res = max(res, int(words[i].size() * words[j].size()));
        }
    }

    return res;
}

int main()
{
    vector<string> words = {"abcw", "baz", "foo", "bar", "fxyz", "abcdef"};
    int ans = maxProduct(words);
    cout << ans << endl;

    return 0;
}