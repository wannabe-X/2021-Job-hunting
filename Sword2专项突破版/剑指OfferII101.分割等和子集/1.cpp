/*
 * @Description: 剑指 Offer II 101. 分割等和子集
 * @Author: Mr. Lee
 * @Date: 2021-09-14 23:39:25
 * @LastEditTime: 2021-09-15 00:09:34
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); sum += nums[i], i++)
        ;
    if (sum & 1)
        return false;

    int target = sum >> 1;

    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = target; j >= nums[i]; j--)
        {
            dp[j] = dp[j - 1] || dp[j - nums[i]];
        }
    }

    return dp[target];
}

int main(void)
{
    vector<int> nums = {1, 2, 3, 5};
    bool ans = canPartition(nums);
    cout << ans << endl;

    return 0;
}