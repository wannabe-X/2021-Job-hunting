/*
 * @Description: 剑指 Offer II 020. 回文子字符串的个数
 * @Author: Mr. Lee
 * @Date: 2021-08-19 00:09:07
 * @LastEditTime: 2021-08-19 00:16:45
 * @LastEditors: Mr. Lee
 */

// 中心扩展法

#include <vector>
#include <iostream>

using namespace std;

int countSubstrings(string s)
{
    int res = 0, n = s.size();

    // 考虑中心是一个字符的情况
    for (int i = 0; i < n; i++)
    {
        int left = i, right = i;
        while (left > -1 && right < n)
        {
            if (s[left] == s[right])
            {
                left--;
                right++;
                res++;
            }
            else
            {
                break;
            }
        }
    }

    // 考虑中心是两个字符的情况
    for (int i = 0; i < n - 1; i++)
    {
        int left = i, right = i + 1;
        while (left > -1 && right < n)
        {
            if (s[left] == s[right])
            {
                left--;
                right++;
                res++;
            }
            else
            {
                break;
            }
        }
    }
    
    // 返回结果
    return res;
}

int main()
{
    string s = "aaa";
    int ans = countSubstrings(s);
    cout << ans << endl;

    return 0;
}