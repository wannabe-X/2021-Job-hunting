/*
 * @Description: 统计占比超过一半的元素
 * @Author: Mr. Lee
 * @Date: 2021-07-09 00:02:59
 * @LastEditTime: 2021-07-09 00:19:35
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int> &nums)
{
    int length = nums.size();
    int count = 0, candiate;
    for (auto &num : nums)
    {
        if (count == 0)
            candiate = num;
        if (candiate == num)
            count++;
        else
            count--;
    }

    count = 0;
    for (auto &num : nums)
    {
        if (candiate == num)
            count++;
    }

    return (count * 2 > length) ? candiate : -1;
}

int main()
{
    vector<int> nums = {1, 2, 5, 9, 5, 9, 5, 5, 5};
    int ans = majorityElement(nums);
    cout << ans << endl;

    return 0;
}