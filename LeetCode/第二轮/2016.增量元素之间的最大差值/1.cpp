/*
 * @Description: 2016. 增量元素之间的最大差值
 * @Author: Mr. Lee
 * @Date: 2022-02-26 10:35:45
 * @LastEditTime: 2022-02-26 10:48:26
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumDifference(vector<int> &nums)
{
    int res = -1;
    for (int i = 0, num_min = nums[0]; i < nums.size(); i++)
    {
        if (num_min < nums[i])
            res = max(res, nums[i] - num_min);
        num_min = min(num_min, nums[i]);
    }
    return res;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 1, 1};
    int ans = maximumDifference(nums);
    cout << ans << endl;

    return 0;
}