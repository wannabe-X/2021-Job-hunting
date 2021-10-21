/*
 * @Description: 45. 跳跃游戏 II
 * @Author: Mr. Lee
 * @Date: 2021-10-18 14:52:45
 * @LastEditTime: 2021-10-18 15:06:25
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int jump(vector<int> &nums)
{
    int maxPos = 0, n = nums.size(), end = 0, step = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (maxPos >= i)
        {
            maxPos = max(maxPos, i + nums[i]);
            if (i == end)
            {
                end = maxPos;
                ++step;
            }
        }
    }
    return step;
}

int main(void)
{
    vector<int> nums = {2, 3, 1, 1, 4};
    int ans = jump(nums);
    cout << ans << endl;

    return 0;
}