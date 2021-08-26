/*
 * @Description: 归并排序
 * @Author: Mr. Lee
 * @Date: 2021-07-22 21:26:08
 * @LastEditTime: 2021-07-22 21:47:52
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

void MergeSort(vector<int> &nums, vector<int> &tmp, int start, int end)
{
    if (start >= end)
        return;
    int mid = start + (end - start) / 2;
    
    int start1 = start, start2 = mid + 1, end1 = mid, end2 = end;
    MergeSort(nums, tmp, start1, end1);
    MergeSort(nums, tmp, start2, end2);

    // 合并左右两端的数组
    int k = start;
    while (start1 <= end1 && start2 <= end2)
    {
        tmp[k++] = nums[start1] < nums[start2] ? nums[start1++] : nums[start2++];
    }
    while (start1 <= end1)
    {
        tmp[k++] = nums[start1++];
    }
    while (start2 <= end2)
    {
        tmp[k++] = nums[start2++];
    }

    for (int i = start; i <= end; i++)
    {
        nums[i] = tmp[i];
    }
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

    vector<int> tmp(nums.size());
    MergeSort(nums, tmp, 0, nums.size() - 1);
    cout << "排序之后:" << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}
