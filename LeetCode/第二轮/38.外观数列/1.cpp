/*
 * @Description: 38. 外观数列
 * @Author: Mr. Lee
 * @Date: 2021-10-15 11:43:20
 * @LastEditTime: 2021-10-15 11:57:53
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string countAndSay(int n)
{
    if (n == 1)
        return "1";

    string res = "1";

    for (int i = 2; i <= n; i++)
    {
        int count = 0;
        string tmp;
        for (int j = 0; j < res.size(); j++)
        {
            if (res[j] != res[j - 1])
            {
                tmp += to_string(count) + res[j - 1];
                count = 0;
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
    int n = 4;
    string ans = countAndSay(n);
    cout << ans << endl;

    return 0;
}