/*
 * @Description: 剑指 Offer 53 - I. 在排序数组中查找数字 I
 * @Author: Mr. Lee
 * @Date: 2021-07-16 00:04:15
 * @LastEditTime: 2021-07-16 00:15:46
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>

using namespace std;

int left_bound(vector<int> &nums, int target)
{
    int left = 0, right = nums.size();
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] > target)
            right = mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

int search(vector<int> &nums, int target)
{
    int left = left_bound(nums, target), count = 0;
    for (int i = left; i < nums.size() && nums[i] == target; count++, i++)
        ;

    return count;
}

int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 6;
    int ans = search(nums, target);
    cout << ans << endl;

    return 0;
}