/*
 * @Description: 剑指 Offer II 104. 排列的数目
 * @Author: Mr. Lee
 * @Date: 2021-09-15 15:55:53
 * @LastEditTime: 2021-09-15 17:02:58
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int combinationSum4(vector<int> &nums, int target)
{
    vector<int> dp(target + 1);
    dp[0] = 1;

    for (int i = 0; i <= target; i++)
    {
        for (auto &num : nums)
        {
            if (i - num >= 0 && dp[i - num] <= INT_MAX - dp[i])
                dp[i] += dp[i - num];
        }
    }

    return dp[target];
}

int main(void)
{
    vector<int> nums = {1, 2, 3};
    int target = 2;
    int ans = combinationSum4(nums, target);
    cout << ans << endl;

    return 0;
}
