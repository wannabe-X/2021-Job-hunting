/*
 * @Description: 930. 和相同的二元子数组
 * @Author: Mr. Lee
 * @Date: 2021-07-08 00:05:37
 * @LastEditTime: 2021-07-08 01:04:02
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

int numSubarraysWithSum(vector<int> &nums, int goal)
{
    int i = 0, j = 0;
    int count = 0;
    while (i < nums.size())
    {
        vector<int> tmp(nums.begin() + i, nums.begin() + j + 1);
        int sum = accumulate(tmp.begin(), tmp.end(), 0);

        if (j == nums.size() - 1)
        {
            if (sum == goal)
                count++;
            i++;
            j = i;
        }
        else
        {
            if (sum < goal)
                j++;
            else if (sum > goal)
            {
                i++;
                j = i;
            }
            else
            {
                count++;
                j++;
            }
        }
    }

    return count;
}

int main()
{
    vector<int> nums = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0};
    int goal = 0;
    int ans = numSubarraysWithSum(nums, goal);
    cout << ans << endl;

    return 0;
}