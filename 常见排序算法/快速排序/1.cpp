/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-08-26 19:21:31
 * @LastEditTime: 2021-08-26 19:36:13
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

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

int main(int argc, char *argv[])
{
    vector<int> nums = {9,8,7,4,5,6,3};
    cout << "排序之前:" << endl;
    for (auto &num : nums)
    {
        cout << num << " ";
    }

    quickSort(nums);
    cout << endl;

    cout << "排序之后:" << endl;
    for (auto &num : nums)
    {
        cout << num << " ";
    }

    return 0;
}