/*
 * @Description: 541. 反转字符串 II
 * @Author: Mr. Lee
 * @Date: 2021-08-20 00:22:40
 * @LastEditTime: 2021-08-20 00:52:44
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>

using namespace std;

void reverseSubStr(string &s, int left, int right)
{
    while (left < right)
    {
        swap(s[left++], s[right--]);
    }
}

string reverseStr(string s, int k)
{
    for (int i = 0; i < s.size(); i += (2 * k))
    {
        reverseSubStr(s, i, min(int(s.size() - 1), i - 1 + k));
    }

    return s;
}

int main()
{
    string s = "abcdefgh";
    int k = 10;
    string ans = reverseStr(s, k);
    cout << ans << endl;

    return 0;
}