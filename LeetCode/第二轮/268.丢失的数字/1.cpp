/*
 * @Description: 268. 丢失的数字
 * @Author: Mr. Lee
 * @Date: 2021-11-06 13:05:27
 * @LastEditTime: 2021-11-06 13:11:21
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int missingNumber(vector<int> &nums)
{
    int res = 0;
    for (int i = 1; i < nums.size() + 1; i++)
        res ^= nums[i - 1] ^ i;
    return res;
}

int main(int argc, char **argv)
{
    vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    int ans = missingNumber(nums);
    cout << ans << endl;

    return 0;
}