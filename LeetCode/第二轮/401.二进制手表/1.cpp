/*
 * @Description: 401. 二进制手表
 * @Author: Mr. Lee
 * @Date: 2021-06-21 09:59:29
 * @LastEditTime: 2021-06-21 10:49:53
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

/* 枚举方法是枚举所有 2^{10}=1024 种灯的开闭组合，即用一个二进制数表示灯的开闭，
其高 4位为小时，低 6 位为分钟。
若小时和分钟的值均在合法范围内，且二进制中 1 的个数为 turnedOn，则将其加入到答案中。 */

vector<string> readBinaryWatch(int turnedOn)
{
    vector<string> res;
    for (int i = 0; i < 1024; ++i)
    {
        int hour = (i >> 6);   // 取出后四位，用来计算小时
        int minute = (i & 63); // 取出前六位，用来计算分钟
        if (hour < 12 && minute < 60 && __builtin_popcount(i) == turnedOn)
            res.push_back(to_string(hour) + ":" + (minute < 10 ? "0" : "") +
                          to_string(minute));
    }

    return res;
}

int main()
{
    // 测试用例
    // int turnedOn = 1;
    // vector<string> ans = readBinaryWatch(turnedOn);
    // for (string s : ans)
    // {
    //     cout << s << endl;
    // }

    int turnedOn;
    cin >> turnedOn;
    vector<string> ans = readBinaryWatch(turnedOn);
    for (string s : ans)
    {
        cout << s << endl;
    }
    return 0;
}
