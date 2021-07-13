/*
 * @Description: 209. 长度最小的子数组
 * @Author: Mr. Lee
 * @Date: 2021-07-09 17:30:51
 * @LastEditTime: 2021-07-09 18:43:11
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int left_bound(vector<int> array, int k)
{
    int i = 0, j = array.size();
    while (i < j)
    {
        int mid = i + (j - i) / 2;
        int sum = accumulate(array.begin(), array.begin() + mid + 1, 0);
        if (sum < k)
            i = mid + 1;
        else
            j = mid;
    }

    return i < array.size() ? i : -1;
}

int minSubArrayLen(int target, vector<int> &nums)
{
    int ans = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
            return 1;
        vector<int> tmp(nums.begin() + i, nums.end());
        int left = left_bound(tmp, target);
        if (left + 1)
            ans = min(ans, left + 1);
    }

    return ans == INT_MAX ? 0 : ans;
}

int main()
{
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    int ans = minSubArrayLen(target, nums);
    cout << ans << endl;

    return 0;
}
