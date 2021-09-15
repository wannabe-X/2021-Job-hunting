/*
 * @Description: 162. 寻找峰值
 * @Author: Mr. Lee
 * @Date: 2021-09-15 00:18:22
 * @LastEditTime: 2021-09-15 00:41:42
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 二分查找
int findPeakElement(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (mid == 0 || nums[mid] > nums[mid - 1])
            left++;
        else
            right--;
    }

    return left - 1;
}

int main(void)
{
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    int ans = findPeakElement(nums);
    cout << ans << endl;
    
    return 0;
}