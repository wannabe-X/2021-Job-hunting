/*
 * @Description: 1185. 一周中的第几天
 * @Author: Mr. Lee
 * @Date: 2022-01-03 22:23:38
 * @LastEditTime: 2022-01-03 22:48:57
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string dayOfTheWeek(int day, int month, int year)
{
    vector<string> v = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    // 使用蔡勒公式 w = y + y/4 + c/4 -2c + 26(m+1)/10 + d - 1, 其中,y是年数(两位数),c是世纪数,m是月数,d是年数
    if (month < 3)
    {
        year--;
        month += 12;
    }
    int c = year / 100, y = year % 100;
    int w = y + int(y / 4) + int(c / 4) - 2 * c + int(26 * (month + 1) / 10) + day - 1;
    w = (w % 7 + 7) % 7;
    return v[w];
}

int main(int argc, char *argv[])
{
    int day = 29, month = 2, year = 2016;
    string ans = dayOfTheWeek(day, month, year);
    cout << ans << endl;

    return 0;
}