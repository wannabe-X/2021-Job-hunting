/*
 * @Description: 453. 最小操作次数使数组元素相等
 * @Author: Mr. Lee
 * @Date: 2021-10-20 00:25:10
 * @LastEditTime: 2021-10-20 00:40:48
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minMoves(vector<int> &nums)
{
    int minVal = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        minVal = min(minVal, nums[i]);
    }

    int res = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        res += (-minVal + nums[i]);
    }

    return res;
}

int main(void)
{
    vector<int> nums = {1000000000};
    int ans = minMoves(nums);
    cout << ans << endl;

    return 0;
}