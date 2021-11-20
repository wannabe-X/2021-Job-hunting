/*
 * @Description: 594. 最长和谐子序列
 * @Author: Mr. Lee
 * @Date: 2021-11-20 23:42:40
 * @LastEditTime: 2021-11-21 00:05:52
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int findLHS(vector<int> &nums)
{
    unordered_map<int, int> m;
    for (int num : nums)
        m[num]++;

    int res = 0;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        if (m.count((*it).first + 1))
            res = max(res, m[(*it).first] + m[(*it).first + 1]);
    }

    return res;
}

int main(int argc, char **argv)
{
    vector<int> nums = {1,1,1,1,1};
    int ans = findLHS(nums);
    cout << ans << endl;

    return 0;
}