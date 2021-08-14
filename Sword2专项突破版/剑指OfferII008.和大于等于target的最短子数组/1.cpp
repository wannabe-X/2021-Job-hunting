/*
 * @Description: 剑指 Offer II 008. 和大于等于 target 的最短子数组
 * @Author: Mr. Lee
 * @Date: 2021-08-13 09:15:13
 * @LastEditTime: 2021-08-13 09:28:18
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int res = INT_MAX, len = 0, sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        len = 0;
        sum = 0;

        for (int j = i; j < nums.size() && (sum < target); j++)
        {
            sum += nums[j];
            len++;
        }

        if (sum >= target)
        {
            res = min(res, len);
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
