#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> res;
vector<int> track;

void backtrack(vector<int> &nums, vector<bool> &used)
{
    if (track.size() == nums.size())
    {
        res.push_back(track);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (used[i] == true)
            continue;
        // 做选择
        used[i] = true;
        track.push_back(nums[i]);
        // 递归
        backtrack(nums, used);
        // 撤销选择
        track.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<bool> used(nums.size(), false);
    backtrack(nums, used);
    return res;
}

int main(void)
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = permute(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
            cout << ans[i][j] << endl;
        cout << endl;
    }
}