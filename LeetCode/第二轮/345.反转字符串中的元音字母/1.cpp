/*
 * @Description: 345. 反转字符串中的元音字母
 * @Author: Mr. Lee
 * @Date: 2021-08-19 00:55:55
 * @LastEditTime: 2021-08-19 01:04:16
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

string reverseVowels(string s)
{
    string tmp = "";
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    for (char c : s)
    {
        if (vowels.count(c))
            tmp += c;
    }

    int lenOfVowels = tmp.size() - 1;
    string res = "";

    for (char c : s)
    {
        if (vowels.count(c))
            res += tmp[lenOfVowels--];
        else
            res += c;
    }

    return res;
}

int main()
{
    string s = "Aa";
    string ans = reverseVowels(s);
    cout << ans << endl;

    return 0;
}
