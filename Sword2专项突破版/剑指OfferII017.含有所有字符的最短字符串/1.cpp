/*
 * @Description: 剑指 Offer II 017. 含有所有字符的最短字符串
 * @Author: Mr. Lee
 * @Date: 2021-08-20 16:10:11
 * @LastEditTime: 2021-08-21 00:02:04
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string minWindow(string s, string t)
{
    int start = 0, minLen = INT_MAX;
    int left = 0, right = 0;
    int match = 0; // 判断子字符串是否匹配到了模式串，子字符串是否包含了模式串所需的全部字符

    unordered_map<char, int> ms, mp;

    // 统计模式串包含的字符个数
    for (auto &c : t)
        mp[c]++;

    while (right < s.size())
    {
        char c1 = s[right];
        // 处理单个字符
        // 判断字串中是否包含模式串中的字符，若包含，则添加到ms中
        if (mp.count(c1))
        {
            ms[c1]++;
            // 若模式串中的某个字符个数已经集齐，则match++
            if (ms[c1] == mp[c1])
                match++;
        }

        right++;

        // 如果match达到模式串中字符的长度
        // 则说明s的子字符串中已经包含了该模式串中的全部字符
        while (match == mp.size())
        {
            // 更新最小子串的长度，并记录子串的起始位置
            if (right - left < minLen)
            {
                start = left;
                minLen = right - left;
            }

            // 比较完s[left,right]的子字符串，应该更新left和ms，以开始比较s中下一个符合条件的子字符串
            char c2 = s[left];
            if (mp.count(c2))
            {
                ms[c2]--;
                if (ms[c2] < mp[c2])
                {
                    match--;
                }
            }

            left++;
        }
    }

    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}

int main()
{
    // s是字符串，t是模式串
    string s = "ADOBECODEBANC", t = "ABC";
    string ans = minWindow(s, t);
    cout << ans << endl;
    return 0;
}
