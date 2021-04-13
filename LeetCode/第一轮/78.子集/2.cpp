#include <iostream>
#include <vector>

using namespace std;

// 解法2：利用回溯算法
vector<vector<int>> res;

void backtrack(vector<int> &nums, int start, vector<int> &track)
{
    res.push_back(track);
    for (int i = start; i < nums.size(); i++)
    {
        track.push_back(nums[i]);
        backtrack(nums, i + 1, track);
        track.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<int> track;
    backtrack(nums, 0, track);
    return res;
}

int main(void)
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = subsets(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << endl;
        cout << endl;
    }
}