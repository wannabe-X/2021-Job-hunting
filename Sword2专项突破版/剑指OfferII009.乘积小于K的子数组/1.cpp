/*
 * @Description: 剑指 Offer II 009. 乘积小于 K 的子数组
 * @Author: Mr. Lee
 * @Date: 2021-08-13 09:51:38
 * @LastEditTime: 2021-08-13 11:08:42
 * @LastEditors: Mr. Lee
 */

// 超出时间限制
#include <iostream>
#include <vector>

using namespace std;

int getConut(vector<int> &nums, int len, int k)
{
    int mul, count = 0;

    for (int i = 0; i < nums.size() - len + 1; i++)
    {
        int j = i;
        long long mul = 1;

        for (; (j < i + len) && (mul < k); j++)
        {
            mul *= nums[j];
        }

        if (j == i + len && mul < k)
            count++;
    }

    return count;
}

int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    int res = 0;

    for (int len = 1; len <= nums.size(); len++)
    {
        res += getConut(nums, len, k);
    }

    return res;
}

int main()
{
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    int ans = numSubarrayProductLessThanK(nums, k);
    cout << ans << endl;

    return 0;
}
