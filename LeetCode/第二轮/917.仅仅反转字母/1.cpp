/*
 * @Description: 917. 仅仅反转字母
 * @Author: Mr. Lee
 * @Date: 2022-02-23 23:45:10
 * @LastEditTime: 2022-02-23 23:54:21
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string reverseOnlyLetters(string s)
{
    string alpha;
    for (char c : s)
    {
        if (isalpha(c))
            alpha += c;
    }

    string res;
    int idx = alpha.size() - 1;
    for (char c : s)
    {
        if (isalpha(c))
            res += alpha[idx--];
        else
            res += c;
    }

    return res;
}

int main(int argc, char *argv[])
{
    string s = "Test1ng-Leet=code-Q!";
    string ans = reverseOnlyLetters(s);
    cout << ans << endl;

    return 0;
}