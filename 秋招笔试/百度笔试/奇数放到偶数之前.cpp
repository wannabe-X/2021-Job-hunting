/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-08-27 17:46:43
 * @LastEditTime: 2021-08-27 18:02:04
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void func(vector<int> &nums)
{
    if (nums.size() <= 1)
        return;
        
    int start = 0, end = nums.size() - 1;

    while (start < end)
    {
        // 从左向右找到一个偶数
        while (start < end && ((nums[start] & 1) == 1))
        {
            start++;
        }

        // 从右向左找到一个奇数
        while (start < end && ((nums[end] & 1) == 0))
        {
            end--;
        }

        // 交换
        int tmp = nums[start];
        nums[start] = nums[end];
        nums[end] = tmp;
    }
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    func(nums);

    for (auto &num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}