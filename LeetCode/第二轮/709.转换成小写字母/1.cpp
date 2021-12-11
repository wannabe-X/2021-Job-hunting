/*
 * @Description: 709. 转换成小写字母
 * @Author: Mr. Lee
 * @Date: 2021-12-12 00:18:48
 * @LastEditTime: 2021-12-12 00:20:57
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string toLowerCase(string s)
{
    for (int i = 0; i < s.size(); i++)
        s[i] = tolower(s[i]);
    return s;
}

int main(int argc, char *argv[])
{
    string s = "LOVELY";
    string ans = toLowerCase(s);
    cout << ans << endl;
    return 0;
}