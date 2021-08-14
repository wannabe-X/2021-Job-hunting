/*
 * @Description: 剑指 Offer II 012. 左右两边子数组的和相等
 * @Author: Mr. Lee
 * @Date: 2021-08-14 11:51:32
 * @LastEditTime: 2021-08-14 13:34:25
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int pivotIndex(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); sum += nums[i++])
        ; 
    int len = nums.size();
    int curSum = 0;
    for (int i = 0; i < len; i++)
    {
        if (sum - nums[i] == 2 * curSum)
        {
            return i;
        }
        curSum += nums[i];
    }
    return -1;
}

int main()
{
    vector<int> nums = {-1, -1, -1, -1, -1, 0};
    int ans = pivotIndex(nums);
    cout << ans << endl;

    return 0;
}