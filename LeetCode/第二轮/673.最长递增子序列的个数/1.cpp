/*
 * @Description: 673. 最长递增子序列的个数
 * @Author: Mr. Lee
 * @Date: 2021-09-20 18:32:55
 * @LastEditTime: 2021-09-20 18:46:25
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size(), maxLen = 0, ans = 0;
    vector<int> dp(n), cnt(n);
    for (int i = 0; i < n; ++i)
    {
        dp[i] = 1;
        cnt[i] = 1;
        for (int j = 0; j < i; ++j)
        {
            if (nums[i] > nums[j])
            {
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j]; // 重置计数
                }
                else if (dp[j] + 1 == dp[i])
                {
                    cnt[i] += cnt[j];
                }
            }
        }
        
        if (dp[i] > maxLen)
        {
            maxLen = dp[i];
            ans = cnt[i]; // 重置计数
        }
        else if (dp[i] == maxLen)
        {
            ans += cnt[i];
        }
    }
    return ans;
}

int main(void)
{
    vector<int> nums = {1, 3, 5, 4, 7};
    int ans = findNumberOfLIS(nums);
    cout << ans << endl;

    return 0;
}