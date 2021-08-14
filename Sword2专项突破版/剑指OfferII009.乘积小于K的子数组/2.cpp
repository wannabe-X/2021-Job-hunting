/*
 * @Description: 剑指 Offer II 009. 乘积小于 K 的子数组
 * @Author: Mr. Lee
 * @Date: 2021-08-13 09:51:38
 * @LastEditTime: 2021-08-13 13:20:50
 * @LastEditors: Mr. Lee
 */

//
#include <iostream>
#include <vector>

using namespace std;

int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    if (k <= 0)
        return 0;
    int ans = 0;

    int product = 1, start = 0, len = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        product *= nums[i];
        len++;
        while (product >= k)
        {
            product /= nums[start++];
            len--;
        }

        ans += len;
    }

    return ans;
}

int main()
{
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    int ans = numSubarrayProductLessThanK(nums, k);
    cout << ans << endl;

    return 0;
}
