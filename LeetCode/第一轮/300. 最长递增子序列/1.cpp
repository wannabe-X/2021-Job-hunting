#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    vector<int> dp(nums.size(), 1);
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
                dp[i] = max(dp[i], 1 + dp[j]);
        }
    }

    int res = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        res = max(res, dp[i]);
    }

    return res;
}

int main(void)
{
    vector<int> array = {1, 4, 3, 4, 2};
    int res = lengthOfLIS(array);
    cout << res << endl;
}