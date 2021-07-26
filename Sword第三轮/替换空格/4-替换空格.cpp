/*
 * @Description: 面试题4 替换空格
 * @Author: Mr. Lee
 * @Date: 2021-07-26 17:06:55
 * @LastEditTime: 2021-07-26 17:44:05
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

string replaceSpace(string s)
{
    int n = s.size();

    if (n == 0)
        return s;

    int numOfSpace = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
            numOfSpace++;
    }

    s.resize(n + 2 * numOfSpace);

    int p1 = n, p2 = s.size();
    while (p1 && p2 > p1)
    {
        if (s[p1] == ' ')
        {
            s[p2--] = '0';
            s[p2--] = '2';
            s[p2--] = '%';
        }
        else
            s[p2--] = s[p1];
        p1--;
    }

    return s;
}

int main()
{
    string s;
    getline(cin, s);

    string ans = replaceSpace(s);
    cout << ans << endl;

    return 0;
}
