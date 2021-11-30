/*
 * @Description:
 * @Author: Mr. Lee
 * @Date: 2021-12-01 00:06:29
 * @LastEditTime: 2021-12-01 00:15:06
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxPower(string s)
{
    int res = 1, count = 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
            count++;
        else
            count = 1;
        res = max(res, count);
    }

    return res;
}

int main(int argc, char *argv[])
{
    string s = "abbcccddddeeeeedcba";
    int ans = maxPower(s);
    cout << ans << endl;
    return 0;
}