/*
 * @Description: 剑指 Offer II 068. 查找插入位置
 * @Author: Mr. Lee
 * @Date: 2021-09-02 10:51:17
 * @LastEditTime: 2021-09-02 10:59:09
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int searchInsert(vector<int> &nums, int target)
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

    return left;
}

int main(void)
{
    vector<int> nums = {1, 3, 5, 6};
    int target = 7;
    int ans = searchInsert(nums, target);
    cout << ans << endl;

    return 0;
}