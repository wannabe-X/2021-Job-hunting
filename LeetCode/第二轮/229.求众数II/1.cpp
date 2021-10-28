/*
 * @Description: 229. 求众数 II
 * @Author: Mr. Lee
 * @Date: 2021-10-22 00:09:28
 * @LastEditTime: 2021-10-22 00:22:03
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    unordered_map<int, int> m;
    vector<int> res;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        m[nums[i]]++;
        if (m[nums[i]] == n / 3 + 1)
        {
            res.push_back(nums[i]);
        }
    }

    return res;
}

int main(void)
{
    vector<int> nums = {3, 2, 3};
    vector<int> ans = majorityElement(nums);
    for (int num : ans)
        cout << num << " ";

    return 0;
}