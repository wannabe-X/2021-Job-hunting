#include <iostream>
#include <vector>
using namespace std;

// 暴力搜索
int maxSubArray(vector<int> &nums)
{
    int sum = 0, ans = INT_MIN;
    vector<int> dp(nums.size());

    for (int i = 0; i < nums.size(); i++)
    {
        dp[i] = nums[i];
    }

    for (int i = 0; i < nums.size(); i++)
    {
        sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            dp[i] = max(dp[i], sum);
        }
    }

    for (int i = 0; i < nums.size(); i++)
        ans = max(ans, dp[i]);

    return ans;
}

int main(void)
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int ans = maxSubArray(nums);
    cout << ans << endl;
    return 0;
}