#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int> findErrorNums(vector<int> &nums)
{
    int n = nums.size(), dup = -1;
    for (int i = 0; i < n; i++)
    {
        int index = abs(nums[i]) - 1;
        if (nums[index] < 0)
            dup = abs(nums[i]);
        else
            nums[index] *= -1;
    }

        for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << endl;

    int missing = -1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
            missing = i + 1;
    }

    return {dup, missing};
}

int main(void)
{
    vector<int> nums = {1,2,2,3,4,5,};
    vector<int> ans = findErrorNums(nums);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
}