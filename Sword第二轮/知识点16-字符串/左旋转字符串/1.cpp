/*
 * @Description: 左旋转字符串
 * @Author: Mr. Lee
 * @Date: 2021-07-02 16:47:14
 * @LastEditTime: 2021-07-02 16:54:00
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

string LeftRotateString(string str, int n)
{
    string a, b;
    for (int i = 0; i < str.size(); i++)
    {
        if (i < n)
            a += str[i];
        else
            b += str[i];
    }

    return (b + a);
}

int main()
{
    string str = "abcXYZdef";
    int n = 3;
    string ans = LeftRotateString(str, n);
    cout << ans << endl;

    return 0;
}
