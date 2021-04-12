#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int> findDisappearedNumbers(vector<int> &nums)
{
    unordered_set<int> mySet;
    vector<int> res;

    for (int i = 0; i < nums.size(); i++)
        mySet.insert(nums[i]);

    for (int i = 1; i < nums.size() + 1; i++)
    {
        if (!mySet.count(i))
            res.push_back(i);
    }
    return res;
}

int main(void)
{
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> ans = findDisappearedNumbers(nums);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
}