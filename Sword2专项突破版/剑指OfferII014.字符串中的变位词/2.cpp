/*
 * @Description: 剑指 Offer II 014. 字符串中的变位词
 * @Author: Mr. Lee
 * @Date: 2021-08-16 11:39:54
 * @LastEditTime: 2021-08-19 11:29:34
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 滑动窗口法解题
bool checkInclusion(string s1, string s2)
{
    if (s2.size() < s1.size())
        return false;

    vector<int> vp(26, 0), vs(26, 0);

    for (int i = 0; i < s1.size(); i++)
    {
        vp[s1[i] - 'a']++;
        vs[s2[i] - 'a']++;
    }

    int left = 0, right = s1.size();
    while (right < s2.size())
    {
        if (vs == vp)
            return true;
        vs[s2[right++] - 'a']++;
        vs[s2[left++] - 'a']--;
    }

    if (vs == vp)
        return true;

    return false;
}

int main()
{
    string s1 = "ab", s2 = "eidboaoo";
    bool ans = checkInclusion(s1, s2);
    cout << boolalpha << ans << endl;

    return 0;
}