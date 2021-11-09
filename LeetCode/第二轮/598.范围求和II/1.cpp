/*
 * @Description: 598.范围求和II
 * @Author: Mr. Lee
 * @Date: 2021-11-07 23:22:54
 * @LastEditTime: 2021-11-07 23:26:15
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxCount(int m, int n, vector<vector<int>> &ops)
{
    int res1 = m, res2 = n;
    for (vector<int> op : ops)
    {
        res1 = min(res1, op[0]);
        res2 = min(res2, op[1]);
    }

    return res1 * res2;
}

int main(int argc, char **argv)
{
    int m = 3;
    int n = 3;
    vector<vector<int>> ops = {{2, 2}, {3, 3}};
    int ans = maxCount(m, n, ops);
    cout << ans << endl;

    return 0;
}