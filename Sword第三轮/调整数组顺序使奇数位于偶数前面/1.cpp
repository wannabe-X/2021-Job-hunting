/*
 * @Description: 调整数组顺序使奇数位于偶数前面
 * @Author: Mr. Lee
 * @Date: 2021-07-30 11:26:02
 * @LastEditTime: 2021-07-30 11:55:36
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

void ReorderOddEven(vector<int> &nums)
{
    if (nums.size() == 0)
        return;

    int left = 0, right = nums.size() - 1;
    while (left < right)
    {
        while (left < right && (nums[left] & 1) != 0)
        {
            left++;
        }

        while (left < right && (nums[right] & 1) == 0)
        {
            right--;
        }

        if (left < right)
        {
            swap(nums[left], nums[right]);
        }
    }
}

int main()
{
    vector<int> v;

    int tmp;
    while (cin >> tmp)
    {
        v.push_back(tmp);
        if (cin.get() == '\n')
            break;
    }

    ReorderOddEven(v);

    for (auto &x : v)
        cout << x << " ";

    return 0;
}