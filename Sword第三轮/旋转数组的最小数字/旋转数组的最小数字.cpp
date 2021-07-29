/*
 * @Description: 旋转数组的最小哦啊数字
 * @Author: Mr. Lee
 * @Date: 2021-07-28 16:06:08
 * @LastEditTime: 2021-07-28 17:40:02
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

int getMinNum(vector<int> &nums, int &left, int &right)
{
    int minIdx = left, i;  
    for (i = left + 1; i < right + 1; i++)
    {
        if (nums[i] < nums[minIdx])
            minIdx = i;
    }

    return nums[i];
}

int Min(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;
    int mid = 0;

    while (nums[left] >= nums[right])
    {
        if (right - left == 1)
        {
            mid = right;
            break;
        }
        int mid = left + (right - left) / 2;

        if (nums[left] == nums[left] && nums[left] == nums[mid])
            return getMinNum(nums, left, right);
        if (nums[mid] >= nums[left])
            left = mid;
        else if (nums[mid] <= nums[right])
            right = mid;
    }

    return nums[mid];
}

int main()
{
    vector<int> nums = {1, 0, 1, 1, 1};
    int ans = Min(nums);
    cout << ans << endl;

    return 0;
}
