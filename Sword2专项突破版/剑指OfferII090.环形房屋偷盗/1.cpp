/*
 * @Description: 剑指 Offer II 090. 环形房屋偷盗
 * @Author: Mr. Lee
 * @Date: 2021-09-10 16:10:32
 * @LastEditTime: 2021-09-10 17:32:19
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMaxValIdx(vector<int> &dp, int right)
{
    int idx = 0;
    for (int i = 0; i < right; i++)
    {
        if (dp[idx] < dp[i])
            idx = i;
    }

    return idx;
}

int func(vector<int> &nums)
{
    int n = nums.size();

    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = nums[1];
    int idx;

    for (int i = 2; i < n; i++)
    {
        idx = getMaxValIdx(dp, i - 1);
        dp[i] = max(dp[i - 1], dp[idx] + nums[i]);
    }

    return dp[n - 1];
}

int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 3)
    {
        if (n == 1)
            return nums[0];
        else if (n == 2)
            return nums[0] > nums[1] ? nums[0] : nums[1];
        else
            return *max_element(nums.begin(), nums.end());
    }
    
    // 比较nums[0,..,n-] 和 nums[1,...,n] 段能偷到的最大值
    vector<int> tmp1(nums.begin(), nums.begin() + n - 1);
    vector<int> tmp2(nums.begin() + 1, nums.end());
    return max(func(tmp1), func(tmp2));
}

int main(void)
{
    vector<int> nums = {1, 2, 3, 1};
    int ans = rob(nums);
    cout << ans;

    return 0;
}