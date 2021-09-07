/*
 * @Description: 剑指 Offer II 084. 含有重复元素集合的全排列 
 * @Author: Mr. Lee
 * @Date: 2021-09-07 09:51:11
 * @LastEditTime: 2021-09-07 09:58:37
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> res;
vector<int> tmp;

bool checkRepeat(vector<vector<int>> &res, vector<int> &t)
{
    for (auto &x : res)
    {
        if (x == t)
            return false;
    }
    return true;
}

void boardtrack(vector<int> &nums, vector<bool> &seen)
{
    if (tmp.size() == nums.size())
    {
        if (checkRepeat(res, tmp))
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
            seen[i] = false;
            tmp.pop_back();
        }
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums)
{
    vector<bool> seen(nums.size(), false);
    boardtrack(nums, seen);
    return res;
}

int main(void)
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = permuteUnique(nums);
    for (auto &x : ans)
    {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}