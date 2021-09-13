/*
 * @Description: 447. 回旋镖的数量
 * @Author: Mr. Lee
 * @Date: 2021-09-13 21:17:05
 * @LastEditTime: 2021-09-13 22:39:02
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 使用hashmap,然后结合排列进行求解
int numberOfBoomerangs(vector<vector<int>> &points)
{
    int res = 0;
    for (auto &x : points)
    {
        unordered_map<int, int> m;
        for (auto &y : points)
        {
            int distance = (x[0] - y[0]) * (x[0] - y[0]) + (x[1] - y[1]) * (x[1] - y[1]);
            m[distance]++;
        }

        for (auto it = m.begin(); it != m.end(); it++)
        {
            int tmp = (*it).second;
            res += tmp * (tmp - 1);
        }
    }

    return res;
}

int main(void)
{
    vector<vector<int>> nums = {{1, 1}, {2, 2}, {3, 3}, {4, 4}};
    int ans = numberOfBoomerangs(nums);
    cout << ans << endl;

    return 0;
}