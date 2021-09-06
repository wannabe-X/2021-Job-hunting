/*
 * @Description: 剑指 Offer II 079. 所有子集
 * @Author: Mr. Lee
 * @Date: 2021-09-06 23:41:30
 * @LastEditTime: 2021-09-07 00:17:32
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> res;
vector<int> tmp;

void boardtrack(vector<int> &nums, int idx)
{
    if (idx == nums.size())
    {
        res.push_back(tmp);
        return;
    }

    boardtrack(nums, idx + 1);
    tmp.push_back(nums[idx]);
    boardtrack(nums, idx + 1);
    tmp.pop_back();
}

vector<vector<int>> subsets(vector<int> &nums)
{
    boardtrack(nums, 0);
    return res;
}

int main(void)
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = subsets(nums);
    for (auto &x : ans)
    {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}