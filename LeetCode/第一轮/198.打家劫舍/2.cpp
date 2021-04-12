#include <iostream>
#include <vector>

using namespace std;

// int rob(vector<int> &nums)
// {
//     int n = nums.size();
//     int dp[n + 2] = {0};
//     for (int i = n - 1; i >= 0; i--)
//         dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);

//     return dp[0];
// }

int rob(vector<int> &nums)
{
    int n = nums.size();
    int dp_i_1 = 0, dp_i_2 = 0, dp_i = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        dp_i = max(dp_i_1, nums[i] + dp_i_2);
        dp_i_2 = dp_i_1;
        dp_i_1 = dp_i;
    }

    return dp_i;
}

int main()
{

    vector<int> s = {2, 7, 9, 3, 1};
    int ans = rob(s);
    cout << ans << endl;
}