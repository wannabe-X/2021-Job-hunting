/*
 * @Description: 1154. 一年中的第几天
 * @Author: Mr. Lee
 * @Date: 2021-12-21 00:01:22
 * @LastEditTime: 2021-12-21 00:37:21
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include<time.h>

using namespace std;

// int dayOfYear(string date)
// {
//     vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//     int year = stoi(date.substr(0, 4)), month = stoi(date.substr(5, 2)), day = stoi(date.substr(8, 2));
//     int res = 0;
//     for (int i = 1; i < month; i++)
//     {
//         res += days[i - 1];
//     }

//     if (month > 2 && ((year % 4 == 0 && year % 100) || (year % 400 == 0)))
//     {
//         res += 1;
//     }

//     res += day;

//     return res;
// }

// 使用时间类
int dayOfYear(string date)
{
    struct tm t;
    strptime(date.c_str(), "%Y-%m-%d", &t);
    return t.tm_yday + 1;
}

int main(int argc, char *argv[])
{
    string date = "2019-01-10";
    int ans = dayOfYear(date);
    cout << ans << endl;

    return 0;
}