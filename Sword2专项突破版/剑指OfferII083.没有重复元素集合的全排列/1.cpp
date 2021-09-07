/*
 * @Description: 剑指 Offer II 083. 没有重复元素集合的全排列
 * @Author: Mr. Lee
 * @Date: 2021-09-07 09:42:47
 * @LastEditTime: 2021-09-07 09:49:33
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> res;
vector<int> tmp;

void boardtrack(vector<int> &nums, vector<bool> &seen)
{
    if (tmp.size() == nums.size())
    {
        res.push_back(tmp);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (!seen[i])
        {
            tmp.push_back(nums[i]);
            seen[i] = true;
            boardtrack(nums, seen);
            tmp.pop_back();
            seen[i] = false;
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<bool> seen(nums.size(), false);
    boardtrack(nums, seen);
    return res;
}

int main(void)
{
    vector<int> nums = {1};
    vector<vector<int>> ans = permute(nums);
    for (auto &x : ans)
    {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }

    return 0;
}