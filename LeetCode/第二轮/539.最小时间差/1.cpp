/*
 * @Description: 539. 最小时间差
 * @Author: Mr. Lee
 * @Date: 2022-01-18 14:50:14
 * @LastEditTime: 2022-01-18 16:14:08
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMinDifference(vector<string> &timePoints)
{
    int res = INT_MAX;
    sort(timePoints.begin(), timePoints.end());

    int h1, h2, m1, m2;

    // 计算首尾的时间差
    h1 = stoi(timePoints[0].substr(0, 2)), m1 = stoi(timePoints[0].substr(3, 2));
    h2 = stoi(timePoints[timePoints.size() - 1].substr(0, 2)), m2 = stoi(timePoints[timePoints.size() - 1].substr(3, 2));
    if (h2 - h1 >= 12)
        res = min(res, (h1 + 24 - h2) * 60 + m1 - m2);

    // 计算连续的最小时间差
    for (int i = 1; i < timePoints.size(); i++)
    {
        h2 = stoi(timePoints[i].substr(0, 2)), m2 = stoi(timePoints[i].substr(3, 2));
        res = min(res, (h2 - h1) * 60 + m2 - m1);
        h1 = h2, m1 = m2;
    }

    return res;
}

int main(int argc, char *argv[])
{
    vector<string> timePoints = {"23:59", "00:00", "10:52", "11:50"};
    int ans = findMinDifference(timePoints);
    cout << ans << endl;

    return 0;
}