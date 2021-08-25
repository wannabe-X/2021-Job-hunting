/*
 * @Description: 剑指 Offer II 018. 有效的回文
 * @Author: Mr. Lee
 * @Date: 2021-08-18 16:47:10
 * @LastEditTime: 2021-08-18 17:10:42
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>

using namespace std;

bool isPalindrome(string s)
{
    string tmp = "";
    for (auto &c : s)
    {
        if (isalpha(c))
            tmp += tolower(c);
        else if (isdigit(c))
            tmp += c;
    }

    int left = 0, right = tmp.size() - 1;
    while (left < right)
    {
        if (tmp[left++] != tmp[right--])
            return false;
    }

    return true;
}

int main()
{
    string s = "0P";
    bool ans = isPalindrome(s);
    cout << boolalpha << ans << endl;

    return 0;
}