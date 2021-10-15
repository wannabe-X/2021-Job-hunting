/*
 * @Description: 38. 外观数列
 * @Author: Mr. Lee
 * @Date: 2021-10-15 11:43:20
 * @LastEditTime: 2021-10-15 21:39:59
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string countAndSay(int n)
{
    string res = "1";

    if (n == 1)
        return res;

    for (int i = 2; i <= n; i++)
    {
        int count = 1;
        string tmp;
        for (int j = 1; j < res.size() + 1; j++)
        {
            if (res[j] != res[j - 1])
            {
                tmp += to_string(count) + res[j - 1];
                count = 1;
            }
            else
                count++;
        }
        res = tmp;
    }

    return res;
}

int main(void)
{
    int n = 5;
    string ans = countAndSay(n);
    cout << ans << endl;

    return 0;
}