/*
 * @Description: 300. 最长递增子序列
 * @Author: Mr. Lee
 * @Date: 2021-07-13 10:46:41
 * @LastEditTime: 2021-07-13 10:58:27
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    vector<int> dp(nums.size(), 1);
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int max_len = 0;
    for (int i = 0; i < dp.size(); i++)
    {
        max_len = max(max_len, dp[i]);
    }

    return max_len;
}

int main()
{
    vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
    int ans = lengthOfLIS(nums);
    cout << ans << endl;

    return 0;
}
