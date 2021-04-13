#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 利用HashMap减少时间复杂度

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> myMap;
    for (int i = 0; i < nums.size(); i++)
        myMap[nums[i]] = i;

    for (int i = 0; i < nums.size(); i++)
    {
        int other = target - nums[i];
        if (myMap.count(other) && myMap[other] - i)
            return {i, myMap[other]};
    }
    return {-1, -1};
}

int main(void)
{
    vector<int> nums = {3, 2, 4};
    int target = 6;

    vector<int> ans = twoSum(nums, target);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
        cout << endl;
    }
}
