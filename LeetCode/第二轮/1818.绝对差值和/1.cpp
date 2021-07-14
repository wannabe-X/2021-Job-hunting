/*
 * @Description: 1818. 绝对差值和
 * @Author: Mr. Lee
 * @Date: 2021-07-14 00:02:31
 * @LastEditTime: 2021-07-14 01:01:05
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static constexpr int mod = 1'000'000'007;

int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> rec(nums1);
    sort(rec.begin(), rec.end());
    int sum = 0, maxn = 0;
    int n = nums1.size();
    for (int i = 0; i < n; i++)
    {
        int diff = abs(nums1[i] - nums2[i]);
        sum = (sum + diff) % mod;
        int j = lower_bound(rec.begin(), rec.end(), nums2[i]) - rec.begin();
        if (j < n)
        {
            maxn = max(maxn, diff - (rec[j] - nums2[i]));
        }
        if (j > 0)
        {
            maxn = max(maxn, diff - (nums2[i] - rec[j - 1]));
        }
    }
    return (sum - maxn + mod) % mod;
}

int main()
{
    vector<int> nums1 = {1, 28, 21},
                nums2 = {9, 21, 20};
    int ans = minAbsoluteSumDiff(nums1, nums2);
    cout << ans << endl;

    return 0;
}
