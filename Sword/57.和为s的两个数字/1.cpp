#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while (left < right)
    {
        int temp = nums[left] + nums[right];

        if (temp == target)
            return {nums[left], nums[right]};
        else if (temp < target)
            left++;
        else
            right--;
    }
    cout << 1<<endl;
    return {nums[left], nums[right]};
}

int main(void)
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 13;
    vector<int> ans = twoSum(nums, target);
    for (int num : ans)
        cout << num << ' ';
    cout << endl;
    return 0;
}