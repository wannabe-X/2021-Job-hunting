#include <iostream>
#include <vector>

using namespace std;

// 利用回溯算法
vector<vector<int>> res;

void backtrack(vector<int> &nums, vector<int> &track, vector<int> &flag)
{
    if (nums.size() == track.size())
    {
        res.push_back(track);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (flag[i])
            continue;
        track.push_back(nums[i]);
        flag[i] = 1;
        backtrack(nums, track, flag);
        track.pop_back();
        flag[i] = 0;
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<int> track;
    vector<int> flag(nums.size(), 0);
    backtrack(nums, track, flag);
    return res;
}

int main(void)
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = permute(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << endl;
        cout << endl;
    }
}