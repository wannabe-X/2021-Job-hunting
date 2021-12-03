/*
 * @Description: 1005. K 次取反后最大化的数组和
 * @Author: Mr. Lee
 * @Date: 2021-12-03 00:44:25
 * @LastEditTime: 2021-12-03 00:55:20
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int largestSumAfterKNegations(vector<int> &nums, int k)
{
    for (int i = 0; i < k; i++)
    {
        sort(nums.begin(), nums.end());
        nums[0] = -nums[0];
    }

    int res = 0;
    for (int num : nums)
        res += num;

    return res;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {3, -1, 0, 2};
    int k = 3;
    int ans = largestSumAfterKNegations(nums, k);
    cout << ans << endl;

    return 0;
}