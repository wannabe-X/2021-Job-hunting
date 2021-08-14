/*
 * @Description: 剑指 Offer II 008. 和大于等于 target 的最短子数组
 * @Author: Mr. Lee
 * @Date: 2021-08-13 09:15:13
 * @LastEditTime: 2021-08-13 09:37:27
 * @LastEditors: Mr. Lee
 */

// 参考解法，滑动窗口解题。先增大窗口，再逐步减小窗口

#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int left = 0, right = 0;
    int sum = 0, res = INT_MAX;
    while (right < nums.size())
    {
        sum += nums[right++];

        while (left <= right && sum >= target)
        {
            res = min(res, right - left);
            sum -= nums[left++];
        }
    }

    return res == INT_MAX ? 0 : res;
}

int main()
{
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1};
    int target = 11;
    int ans = minSubArrayLen(target, nums);
    cout << ans << endl;

    return 0;
}
