#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int> findErrorNums(vector<int> &nums)
{
    // 时间复杂度为nlogn;
    sort(nums.begin(), nums.end());
    int preValue = nums[0], repeat, res = 0;

    // 寻找重复元素
    for (int i = 1; i < nums.size(); i++)
    {

        if (preValue == nums[i])
        {
            repeat = nums[i];
            break;
        }
        preValue = nums[i];
    }

    for (int i = 1; i <= nums.size(); i++)
    {
        res ^= (i ^ nums[i - 1]);
    }

    return {repeat, repeat ^ res};
}

int main(void)
{
    vector<int> nums = {1,2,2,4};
    vector<int> ans = findErrorNums(nums);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
}