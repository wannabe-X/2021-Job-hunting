#include <iostream>
#include <vector>
#include <algorithm>

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

//
static bool cmp(const vector<int> &a, const vector<int> &b)
{
    if (a[0] == b[0])
        return a[1] > b[1];
    else
        return a[0] < b[0];
}

int maxEnvelopes(vector<vector<int>> &envelopes)
{
    sort(envelopes.begin(), envelopes.end(), cmp);

    vector<int> h;
    for (int i = 0; i < envelopes.size(); i++)
        h.push_back(envelopes[i][1]);

    int res = lengthOfLIS(h);

    return res;
}

int main()
{
    // {5, 4}, {6, 4}, {6, 7}, {2, 3}
    vector<vector<int>> envelopes = {{1, 1}, {1, 1}, {1, 1}};
    int ans = maxEnvelopes(envelopes);
    cout << ans << endl;
}
