/*
 * @Description: 223. 矩形面积
 * @Author: Mr. Lee
 * @Date: 2021-09-30 09:05:03
 * @LastEditTime: 2021-09-30 11:21:12
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
{
    vector<int> tmp1, tmp2;
    int res = 0;

    res += (abs(ax2 - ax1) * abs(ay2 - ay1) + abs(bx2 - bx1) * abs(by2 - by1));

    if ((ax1 >= bx1 && ax1 <= bx2) || (bx1 >= ax1 && bx1 <= ax2))
    {
        tmp1 = {ax1, ax2, bx1, bx2};
        sort(tmp1.begin(), tmp1.end());
    }

    if ((ay1 >= by1 && ay1 <= by2) || (by1 >= ay1 && by1 <= ay2))
    {
        tmp1 = {ay1, ay2, by1, by2};
        sort(tmp2.begin(), tmp2.end());
    }

    if (!tmp1.empty() && !tmp2.empty())
    {
        res -= (abs(tmp1[2] - tmp1[1]) * abs(tmp2[2] - tmp2[1]));
    }

    return res;
}

int main(void)
{
    int ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2;
    int ans = computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
    cout << ans << endl;

    return 0;
}