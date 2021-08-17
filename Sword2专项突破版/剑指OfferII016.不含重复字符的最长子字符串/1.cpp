/*
 * @Description: 剑指 Offer II 016. 不含重复字符的最长子字符串
 * @Author: Mr. Lee
 * @Date: 2021-08-16 23:29:38
 * @LastEditTime: 2021-08-17 00:12:32
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> m;
    int left = 0, right = 0;
    int res = 0;

    while (right < s.size())
    {
        char c = s[right++];
        m[c]++;

        while (left < right && m[c] > 1)
        {
            char c1 = s[left];
            m[c1]--;
            left++;
        }

        res = max(res, right - left);
    }

    return res;
}

int main()
{
    string s = "pwwkew";
    int ans = lengthOfLongestSubstring(s);
    cout << ans << endl;

    return 0;
}
