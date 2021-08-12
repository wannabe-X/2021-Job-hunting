/*
 * @Description: 剑指 Offer II 006. 排序数组中两个数字之和
 * @Author: Mr. Lee
 * @Date: 2021-08-12 15:23:15
 * @LastEditTime: 2021-08-12 15:27:58
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    int left = 0, right = numbers.size() - 1;
    while (left < right)
    {
        int tmpSum = numbers[left] + numbers[right];
        if (tmpSum > target)
            right--;
        else if (tmpSum < target)
            left++;
        else
            return {left, right};
    }

    return {};
}

int main()
{
    vector<int> nums = {1, 2, 4, 6, 10};
    int target = 8;
    vector<int> ans = twoSum(nums, target);
    for (auto &x : ans)
        cout << x << " ";

    return 0;
}