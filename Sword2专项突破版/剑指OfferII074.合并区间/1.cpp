/*
 * @Description: 剑指 Offer II 074. 合并区间
 * @Author: Mr. Lee
 * @Date: 2021-09-04 00:41:33
 * @LastEditTime: 2021-09-04 01:22:03
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if (intervals.size() == 0)
    {
        return {};
    }
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ret{intervals[0]};
    for (int i = 1; i < intervals.size(); ++i)
    {
        if (intervals[i][0] <= ret.back()[1])
        {
            ret.back()[1] = max(ret.back()[1], intervals[i][1]);
        }
        else
        {
            ret.emplace_back(intervals[i]);
        }
    }
    return ret;
}

int main(void)
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {12, 15}};
    vector<vector<int>> ans = merge(intervals);
    for (auto &x : ans)
    {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }

    return 0;
}