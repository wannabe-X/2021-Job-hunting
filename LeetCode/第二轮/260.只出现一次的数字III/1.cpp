/*
 * @Description: 260. 只出现一次的数字 III
 * @Author: Mr. Lee
 * @Date: 2021-10-30 10:18:11
 * @LastEditTime: 2021-10-30 10:58:58
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> singleNumber(vector<int> &nums)
{
    unordered_map<int, int> m;
    for (int num : nums)
    {
        m[num]++;
    }

    vector<int> res;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        if ((*it).second < 2)
            res.push_back((*it).first);
    }

    return res;
}

int main(void)
{
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    vector<int> ans = singleNumber(nums);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}