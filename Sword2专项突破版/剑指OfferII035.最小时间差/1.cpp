/*
 * @Description: 剑指 Offer II 035. 最小时间差
 * @Author: Mr. Lee
 * @Date: 2021-08-23 20:06:59
 * @LastEditTime: 2021-08-23 22:23:11
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMinutes(vector<string> &timePoints, int i, int j)
{
    int tmp = 0;
    int min2 = atoi(timePoints[j].substr(3, 2).c_str()),
        min1 = atoi(timePoints[i].substr(3, 2).c_str()),
        h2 = atoi(timePoints[j].substr(0, 2).c_str()),
        h1 = atoi(timePoints[i].substr(0, 2).c_str());

    if (j == 0 && i == timePoints.size() - 1 && h2 < 12)
        h2 += 24;

    if (min2 < min1)
    {
        tmp += (h2 - h1 - 1) * 60 + (60 + min2 - min1);
    }
    else
    {
        tmp += (h2 - h1) * 60 + (min2 - min1);
    }

    return tmp;
}

int findMinDifference(vector<string> &timePoints)
{
    int res = INT_MAX;
    sort(timePoints.begin(), timePoints.end());

    for (int i = 1; i < timePoints.size(); i++)
    {
        // 计算相邻两个时间点最小的时间差
        res = min(res, getMinutes(timePoints, i - 1, i));
    }

    // 计算首尾两项的时间差
    if (getMinutes(timePoints, timePoints.size() - 1, 0) > 0)
        res = min(res, getMinutes(timePoints, timePoints.size() - 1, 0));

    return res;
}

int main()
{
    vector<string> str = {"05:31", "22:08", "00:35"};
    int ans = findMinDifference(str);
    cout << ans << endl;

    // for (auto &x : timePoints)
    // {
    //     cout << x << endl;
    // }

    return 0;
}