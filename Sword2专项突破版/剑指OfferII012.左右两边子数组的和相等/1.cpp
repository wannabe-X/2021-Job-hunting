/*
 * @Description: 剑指 Offer II 012. 左右两边子数组的和相等
 * @Author: Mr. Lee
 * @Date: 2021-08-14 11:51:32
 * @LastEditTime: 2021-08-14 13:25:42
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>

using namespace std;

int getSum(vector<int> &nums, int start, int end)
{
    int sum = 0;
    for (int i = start; i < end; i++)
        sum += nums[i];

    return sum;
}

int pivotIndex(vector<int> &nums)
{
    int left = 0, right = nums.size();
    int leftSum, rightSum;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        leftSum = getSum(nums, 0, mid);
        rightSum = getSum(nums, mid + 1, nums.size());

        if (leftSum < rightSum)
            left = mid + 1;
        else
            right = mid;
    }

    leftSum = getSum(nums, 0, left);
    rightSum = getSum(nums, left + 1, nums.size());

    return leftSum == rightSum ? left : -1;
}

int main()
{
    vector<int> nums = {-1,-1,-1,-1,-1,0};
    int ans = pivotIndex(nums);
    cout << ans << endl;

    return 0;
}