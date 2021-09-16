/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-16 15:25:02
 * @LastEditTime: 2021-09-16 16:26:16
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void QuickSort(vector<int> &nums)
{
    stack<int> stk;
    stk.push(nums.size() - 1);
    stk.push(0);
    while (!stk.empty())
    {
        int low = stk.top();
        stk.pop();
        int high = stk.top();
        stk.pop();
        int i = low, j = high;
        if (i >= j)
            continue;
        int pivot = nums[i];
        while (i < j)
        {
            while (i < j && nums[j] >= pivot)
                j--;
            nums[i] = nums[j];
            while (i < j && nums[i] < pivot)
                i++;
            nums[j] = nums[i];
        }
        nums[i] = pivot;
        stk.push(high);
        stk.push(i + 1);
        stk.push(i - 1);
        stk.push(low);
    }
}

int main(void)
{
    vector<int> nums = {9, 8, 7, 6, 5, 4};
    cout << "排序之前:" << endl;
    for (auto &num : nums)
        cout << num << " ";
    QuickSort(nums);

    cout << endl;

    cout << "排序之后:" << endl;
    for (auto &num : nums)
        cout << num << " ";

    return 0;
}