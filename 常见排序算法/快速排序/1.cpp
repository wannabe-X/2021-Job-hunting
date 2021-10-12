/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-08-26 19:21:31
 * @LastEditTime: 2021-10-12 15:22:14
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

// 非递归
void quickSort(vector<int> &nums)
{
    stack<int> s;
    s.push(nums.size() - 1);
    s.push(0);

    while (!s.empty())
    {
        int low = s.top();
        s.pop();
        int high = s.top();
        s.pop();

        int i = low, j = high;

        if (i >= j)
            continue;

        int pivot = nums[i]; // 基准

        while (i < j)
        {
            // 从右向左
            while (i < j && nums[j] >= pivot)
            {
                j--;
            }
            nums[i] = nums[j];

            // 从左到右
            while (i < j && nums[i] < pivot)
            {
                i++;
            }

            nums[j] = nums[i];
        }

        nums[i] = pivot;

        // 右半边
        s.push(high);
        s.push(i + 1);

        // 左半边
        s.push(i - 1);
        s.push(low);
    }
}

// 递归
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

int main(int argc, char *argv[])
{
    vector<int> nums = {9, 8, 7, 4, 5, 6, 3};
    cout << "排序之前:" << endl;
    for (auto &num : nums)
    {
        cout << num << " ";
    }

    quickSort(nums);                     // 非递归
    QuickSort(nums, 0, nums.size() - 1); // 递归
    cout << endl;

    cout << "排序之后:" << endl;
    for (auto &num : nums)
    {
        cout << num << " ";
    }

    return 0;
}