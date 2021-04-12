#include <iostream>
#include <vector>

using namespace std;

int cycleRob(vector<int> &nums, int start, int end)
{
    int dp_i_1 = 0, dp_i_2 = 0, dp_i = 0;
    for (int i = end; i >= start; i--)
    {
        dp_i = max(dp_i_1, nums[i] + dp_i_2);
        dp_i_2 = dp_i_1;
        dp_i_1 = dp_i;
    }

    return dp_i;
}

int rob(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;

    if (nums.size() == 1)
        return nums[0];

    int n = nums.size();
    int ans = max(cycleRob(nums, 0, n - 2), cycleRob(nums, 1, n - 1));
    return ans;
}

int main()
{

    vector<int> s = {2};
    int ans = rob(s);
    cout << ans << endl;
}