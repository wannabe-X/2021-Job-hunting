#include <iostream>
#include <vector>

using namespace std;

// 解法1：利用数学归纳的思想
vector<vector<int> > subsets(vector<int> &nums)
{
    if (nums.empty())
        return {{}};

    int n = nums.back();
    nums.pop_back();

    vector<vector<int>> res = subsets(nums);

    int subsets_size = res.size();
    for (int i = 0; i < subsets_size; i++)
    {
        res.push_back(res[i]);
        res.back().push_back(n);
    }
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