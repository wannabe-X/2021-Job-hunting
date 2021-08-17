/*
 * @Description: 剑指 Offer II 014. 字符串中的变位词
 * @Author: Mr. Lee
 * @Date: 2021-08-16 11:39:54
 * @LastEditTime: 2021-08-16 21:54:58
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool checkInclusion(string s1, string s2)
{

    sort(s1.begin(), s1.end());
    for (int i = 0; i < int(s2.size() - s1.size() + 1); i++)
    {
        cout << i << endl;
        string temp = s2.substr(i, s1.size());
        sort(temp.begin(), temp.end());
        if (s1 == temp)
            return true;
    }

    return false;
}

int main()
{
    string s1 = "horse", s2 = "ros";
    bool ans = checkInclusion(s1, s2);
    cout << ans << endl;

    return 0;
}