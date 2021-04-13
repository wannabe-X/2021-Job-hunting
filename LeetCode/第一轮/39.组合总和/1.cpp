#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 利用回溯算法
vector<vector<int>> res;
int sum = 0;

void backtrack(vector<int> &nums, vector<int> &track, int target)
{
    // base case
    if (sum == target)
    {
        res.push_back(track);
        return;
    }

    if (sum > target)
    {
        return;
    }

    // 遍历
    for (int i = 0; i < nums.size(); i++)
    {
        // 做选择
        track.push_back(nums[i]);
        sum += nums[i];
        // 递归
        backtrack(nums, track, target);
        // 撤销选择
        track.pop_back();
        sum -= nums[i];
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<int> track;
    backtrack(candidates, track, target);

    // 剪枝 去掉重复结果
    for (int i = 0; i < res.size(); i++)
        sort(res[i].begin(), res[i].end());
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());

    return res;
}

int main(void)
{
    vector<int> nums = {3,5,8};
    int target = 11;
    vector<vector<int>> ans = combinationSum(nums, target);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << endl;
        cout << endl;
    }
}