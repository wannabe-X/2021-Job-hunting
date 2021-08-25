/*
 * @Description: 剑指 Offer II 032. 有效的变位词
 * @Author: Mr. Lee
 * @Date: 2021-08-20 00:03:25
 * @LastEditTime: 2021-08-20 00:10:59
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool isAnagram(string s, string t)
{
    if (s.size() || t.size() || s.size() != t.size())
    {
        return false;
    }
    
    unordered_map<char, int> ms, mt;
    int flag = false;
    for (int i = 0; i < s.size(); i++)
    {
        ms[s[i]]++;
        mt[t[i]]++;
        if (s[i] != t[i])
            flag = true;
    }

    return (flag && ms == mt);
}

int main()
{
    string s = "rat", t = "car";
    bool ans = isAnagram(s, t);
    cout << boolalpha << ans << endl;

    return 0;
}
