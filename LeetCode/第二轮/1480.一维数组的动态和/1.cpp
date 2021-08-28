/*
 * @Description: 1480. 一维数组的动态和
 * @Author: Mr. Lee
 * @Date: 2021-08-28 00:33:24
 * @LastEditTime: 2021-08-28 00:46:13
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> runningSum(vector<int> &nums)
{
    for (int i = 1; i < nums.size(); i++)
        nums[i] += nums[i - 1];

    return nums;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans = runningSum(nums);
    for (auto &num : nums)
    {
        cout << num << " ";
    }

    return 0;
}
