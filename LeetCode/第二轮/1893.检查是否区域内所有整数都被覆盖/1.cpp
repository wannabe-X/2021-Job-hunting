/*
 * @Description: 1893. 检查是否区域内所有整数都被覆盖
 * @Author: Mr. Lee
 * @Date: 2021-07-23 00:04:18
 * @LastEditTime: 2021-07-23 00:56:05
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// bool isCovered(vector<vector<int>> &ranges, int left, int right)
// {
//     unordered_set<int> s;
//     for (auto &range : ranges)
//     {
//         for (int i = range[0]; i <= range[1]; i++)
//         {
//             s.insert(i);
//         }
//     }

//     for (int i = left; i <= right; i++)
//     {
//         if (!s.count(i))
//             return false;
//     }

//     return true;
// }

bool isCovered(vector<vector<int>> &ranges, int left, int right)
{
    // diff[i] 对应覆盖整数 i 的区间数量相对于覆盖 i−1 的区间数量变化量
    vector<int> diff(52, 0); // 差分数组
    for (auto &&range : ranges)
    {
        ++diff[range[0]];
        --diff[range[1] + 1];
    }

    // 前缀和
    int curr = 0;
    for (int i = 1; i <= 50; ++i)
    {
        curr += diff[i];
        if (i >= left && i <= right && curr <= 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<vector<int>> ranges = {{1, 2}, {3, 4}, {5, 6}};
    int left = 2, right = 5;
    bool ans = isCovered(ranges, left, right);
    cout << boolalpha << ans << endl;

    return 0;
}
