/*
 * @Description: 剑指 Offer 42. 连续子数组的最大和
 * @Author: Mr. Lee
 * @Date: 2021-07-17 00:11:00
 * @LastEditTime: 2021-07-17 00:18:01
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int> &nums)
{
    int tmp = 0, res = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        tmp += nums[i];
        res = max(res, tmp);
        tmp = max(0, tmp);
    }

    return res;
}

int main()
{
    vector<int> nums = {-2};
    int ans = maxSubArray(nums);
    cout << ans << endl;

    return 0;
}
