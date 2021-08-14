/*
 * @Description: 剑指 Offer II 010. 和为 k 的子数组
 * @Author: Mr. Lee
 * @Date: 2021-08-14 11:17:02
 * @LastEditTime: 2021-08-14 11:40:51
 * @LastEditors: Mr. Lee
 */

// 该解法只能针对整数，如果出现了负数就乱套了

#include <vector>
#include <iostream>

using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    int res = 0;
    int left = 0, right = 0;
    int sum = 0;
    while (right < nums.size())
    {
        sum += nums[right++];

        while (left < right && sum > k)
        {
            sum -= nums[left++];
        }
        if (left < right && sum == k)
        {
            res++;
        }
    }

    return res;
}

int main()
{
    vector<int> nums = {-1,-1,1};
    int k = 0;
    int ans = subarraySum(nums, k);
    cout << ans << endl;

    return 0;
}