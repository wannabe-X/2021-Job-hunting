#include <iostream>
#include <vector>

using namespace std;

int dp(vector<int> &nums, vector<int> &memo, int start)
{
    if (start >= nums.size())
        return 0;
    if (memo[start] != -1)
        return memo[start];

    int res = max(dp(nums, memo, start + 1), nums[start] + dp(nums, memo, start + 2));

    memo[start] = res;

    return res;
}

int rob(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    else
    {
        vector<int> memo(nums.size(), -1);
        return dp(nums, memo, 0);
    }
}

int main()
{

    vector<int> s = {2,7,9,3,1};
    int ans = rob(s);
    cout << ans << endl;
}