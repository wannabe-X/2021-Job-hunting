/*
 * @Description: 剑指 Offer II 089. 房屋偷盗
 * @Author: Mr. Lee
 * @Date: 2021-09-10 15:23:48
 * @LastEditTime: 2021-09-10 16:28:54
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 2)
    {
        if (n == 1)
            return nums[0];
        else
            return nums[0] > nums[1] ? nums[0] : nums[1];
    }

    vector<int> dp(n);

    dp[0] = nums[0], dp[1] = nums[1];
    for (int i = 2; i < n; i++)
    {
        auto maxVal = max_element(dp.begin(), dp.begin() + i - 1);
        dp[i] = max(dp[i - 1], *maxVal + nums[i]);
    }

    return dp[n - 1];
}

int main(void)
{
    vector<int> nums = {2, 3,2};
    int ans = rob(nums);
    cout << ans;

    return 0;
}