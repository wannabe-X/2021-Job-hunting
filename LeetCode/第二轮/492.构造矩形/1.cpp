/*
 * @Description: 492. 构造矩形
 * @Author: Mr. Lee
 * @Date: 2021-10-23 14:25:59
 * @LastEditTime: 2021-10-23 14:36:00
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// vector<int> constructRectangle(int area)
// {
//     vector<int> res;
//     int sqt = sqrt(area), L = sqt, W = sqt;
//     while (L * W != area)
//     {
//         if (L * W < area)
//             L++;
//         else if (L * W > area)
//             W--;
//     }

//     return {L, W};
// }

vector<int> constructRectangle(int area)
{
    int W = sqrt(area);
    while (area % W)
        W--;
    return {area / W, W};
}

int main(void)
{
    int area = 10000000;
    vector<int> ans = constructRectangle(area);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}