/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-06 00:20:07
 * @LastEditTime: 2021-09-06 00:32:59
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int search(vector<int> &nums, int target)
{
    int left = 0, right = nums.size();
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }

    if (left != nums.size() && nums[left] == target)
        return left;

    return -1;
}

int main(void)
{
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    int ans = search(nums, target);
    cout << ans << endl;

    return 0;
}