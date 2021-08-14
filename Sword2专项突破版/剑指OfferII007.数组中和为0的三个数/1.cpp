/*
 * @Description: 剑指 Offer II 007. 数组中和为 0 的三个数
 * @Author: Mr. Lee
 * @Date: 2021-08-13 12:02:18
 * @LastEditTime: 2021-08-13 12:41:39
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> res;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
            
        int left = i + 1, right = n - 1;
        while (left < right)
        {
            int tmpSum = nums[i] + nums[left] + nums[right];
            if (tmpSum == 0)
            {
                res.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;

                left++;
                right--;
            }
            else if (tmpSum > 0)
                right--;
            else
                left++;
        }
    }

    return res;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = threeSum(nums);
    for (auto x : ans)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}
