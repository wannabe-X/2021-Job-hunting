/*
 * @Description: 15. 三数之和
 * @Author: Mr. Lee
 * @Date: 2021-09-13 12:39:41
 * @LastEditTime: 2021-09-13 19:26:28
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    int len = nums.size();
    if (len < 3)
        return {};

    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < len - 2; i++)
    {
        if (nums[i] > 0)
            return res;
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1, right = len - 1;
        while (left < right)
        {
            int tSum = nums[i] + nums[left] + nums[right];
            if (tSum > 0)
                right--;
            else if (tSum < 0)
                left++;
            else
            {
                vector<int> tmp;
                tmp = {nums[i], nums[left], nums[right]};
                res.push_back(tmp);
                while (left < right && nums[left + 1] == nums[left])
                    left++;
                while (left < right && nums[right - 1] == nums[right])
                    right--;
                left++;
                right--;
            }
        }
    }
    return res;
}

int main(void)
{
    return 0;
}