#include <iostream>
#include <vector>
using namespace std;

// 动态规划
// 转移方程： 若dp[i−1]≤0,说明dp[i−1]对dp[i] 产生负贡献，即dp[i−1]+nums[i]≤nums[i]
// 若产生正贡献，则将nums[i]加进来，否则取dp[i] = nums[i]
int maxSubArray(vector<int> &nums)
{
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    int ans = dp[0];
    for (int i = 1; i < nums.size(); i++)
    {
        // dp[i] = dp[i - 1] > 0 ? dp[i - 1] + nums[i] : nums[i];
        dp[i] = max(dp[i - 1], 0) + nums[i];
        ans = max(dp[i], ans);
    }

    return ans;
}

int main(void)
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int ans = maxSubArray(nums);
    cout << ans << endl;
    return 0;
}