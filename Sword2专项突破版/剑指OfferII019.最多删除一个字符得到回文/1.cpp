/*
 * @Description: 剑指 Offer II 019. 最多删除一个字符得到回文
 * @Author: Mr. Lee
 * @Date: 2021-08-19 14:56:34
 * @LastEditTime: 2021-08-19 16:49:23
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

// 判断s[left,right]的子字符串是否是回文的
bool isPalindrome(string &s, int left, int right)
{
    while (left < right)
    {
        if (s[left++] != s[right--])
            return false;
    }

    return true;
}

bool validPalindrome(string s)
{
    int i = 0, n = s.size();
    // 找到引发不是回文的字符索引
    for (; i < n / 2; i++)
    {
        if (s[i] != s[n - 1 - i])
            break;
    }

    // 判断删除该索引后，是否可以构成回文
    // 也就是判断删除索引为n-1-i的字符后，[i,n-2-i] 是否可以构成回文
    // 判断删除索引为i的字符后，[i+1,n-1-i] 是否可以构成回文
    return i == n / 2 || isPalindrome(s, i, n - 2 - i) || isPalindrome(s, i + 1, n - i - 1);
}

int main()
{
    string s = "abcaa";
    bool ans = validPalindrome(s);
    cout << boolalpha << ans << endl;

    return 0;
}