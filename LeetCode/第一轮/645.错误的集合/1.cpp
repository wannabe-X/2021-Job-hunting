#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int> findErrorNums(vector<int> &nums)
{
    unordered_set<int> mySet;
    vector<int> res;
    int preValue = nums[0];

    sort(nums.begin(),nums.end());

    mySet.insert(nums[0]);

    for (int i = 1; i < nums.size(); i++)
    {
        if (preValue == nums[i])
            res.push_back(nums[i]);
        mySet.insert(nums[i]);
        preValue = nums[i];
    }

    for (int i = 1; i < nums.size() + 1; i++)
    {
        if (!mySet.count(i))
            res.push_back(i);
    }
    return res;
}

int main(void)
{
    vector<int> nums = {2,3,2};
    vector<int> ans = findErrorNums(nums);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
}