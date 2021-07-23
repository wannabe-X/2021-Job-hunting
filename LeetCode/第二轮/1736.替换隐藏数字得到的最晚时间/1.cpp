/*
 * @Description: 1736. 替换隐藏数字得到的最晚时间
 * @Author: Mr. Lee
 * @Date: 2021-07-24 00:23:22
 * @LastEditTime: 2021-07-24 01:11:48
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

// string maximumTime(string time)
// {
//     string res;
//     int count = 0;
//     for (int k = 0; k < time.size(); k++)
//     {
//         if (isdigit(time[k]))
//             count++;
//     }

//     for (int i = 23; i > -1; i--)
//     {
//         for (int j = 59; j > -1; j--)
//         {
//             res.clear();
//             int tmp = 0;
//             res += (i < 10 ? '0' + to_string(i) : to_string(i));
//             res += ':';
//             res += (j < 10 ? '0' + to_string(j) : to_string(j));

//             for (int k = 0; k < time.size(); k++)
//             {
//                 if (time[k] != ':' && time[k] == res[k])
//                     tmp++;
//             }

//             if (tmp == count)
//                 return res;
//         }
//     }

//     return res;
// }

string maximumTime(string time)
{
    if (time[0] == '?')
        time[0] = time[1] < '4' || time[1] == '?' ? '2' : '1';
    if (time[1] == '?')
        time[1] = time[0] > '1' ? '3' : '9';
    if (time[3] == '?')
        time[3] = '5';
    if (time[4] == '?')
        time[4] = '9';

    return time;
}

int main()
{
    string time = "2?:?0";
    string ans = maximumTime(time);
    cout << ans << endl;
    return 0;
}
