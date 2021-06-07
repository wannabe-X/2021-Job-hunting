#include <iostream>
#include <vector>

using namespace std;

int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; sum += nums[i], i++)
        ;
    if (sum < target || (sum - target) % 2)
    {
        return 0;
    }
    int neg = (sum - target) / 2;
    /*
        定义二维数组 dp，其中 dp[i][j] 表示在数组 nums 的前 i 个数中选取元素，
        使得这些元素之和等于 j 的方案数。假设数组 nums 的长度为 n，
        则最终答案为dp[n][neg]。

    */

    vector<vector<int>> res(n + 1, vector<int>(neg + 1, 0));
    res[0][0] = 1;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < neg + 1; j++)
        {
            res[i][j] = res[i - 1][j];
            if (j >= nums[i - 1])
                res[i][j] += res[i - 1][j - nums[i - 1]];
        }
    }

    return res[n][neg];
}

int main()
{
    int n, idx = 0;
    cin >> n;
    vector<int> nums(n);
    while (cin >> nums[idx++] && idx < n)
        ;
    int target;
    cin >> target;
    int ans = findTargetSumWays(nums, target);
    cout << ans << endl;

    return 0;
}