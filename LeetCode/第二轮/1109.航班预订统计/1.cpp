/*
 * @Description: 1109. 航班预订统计
 * @Author: Mr. Lee
 * @Date: 2021-08-31 00:32:20
 * @LastEditTime: 2021-08-31 01:08:25
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 暴力解法 超时
// vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
// {
//     vector<int> res(n);

//     for (int i = 0; i < bookings.size(); i++)
//     {
//         for (int j = bookings[i][0]; j <= bookings[i][1]; j++)
//         {
//             res[j - 1] += bookings[i][2];
//         }
//     }

//     return res;
// }

// 差分法
vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
{
    vector<int> diff(n);
    for (auto &booking : bookings)
    {
        diff[booking[0] - 1] += booking[2];
        if (booking[1] < n)
            diff[booking[1]] -= booking[2];
    }

    for (int i = 1; i < n; i++)
    {
        diff[i] += diff[i - 1];
    }

    return diff;
}

int main(void)
{
    vector<vector<int>> bookings{{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};
    int n = 5;
    vector<int> ans = corpFlightBookings(bookings, n);
    for (int num : ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}