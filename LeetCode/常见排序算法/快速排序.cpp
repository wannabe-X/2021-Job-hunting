/*
 * @Description: 快速排序
 * @Author: Mr. Lee
 * @Date: 2021-07-22 22:05:31
 * @LastEditTime: 2021-07-22 22:34:37
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

void QuickSort(vector<int> &nums, int low, int high)
{
    if (low >= high)
        return;

    int first = low, last = high;
    int pivot = nums[low]; // 基准
    while (first < last)
    {
        while (first < last && nums[last] >= pivot)
            last--;
        if (first < last)
            nums[first++] = nums[last];

        while (first < last && nums[first] <= pivot)
            first++;
        if (first < last)
            nums[last--] = nums[first];
    }

    nums[first] = pivot;

    QuickSort(nums, low, first - 1);
    QuickSort(nums, first + 1, high);
}

int main()
{
    vector<int> nums{5, 2, 4, 6, 1, 3};
    cout << "排序之前:" << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    QuickSort(nums, 0, nums.size() - 1);
    cout << "排序之后:" << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}