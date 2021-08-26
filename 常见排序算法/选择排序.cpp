/*
 * @Description: 选择排序
 * @Author: Mr. Lee
 * @Date: 2021-07-22 17:53:33
 * @LastEditTime: 2021-07-22 21:02:46
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

void SelectionSort(vector<int> &nums)
{
    int j, min_index;
    for (int i = 0; i < nums.size(); i++)
    {
        min_index = i;
        for (j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] < nums[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
            swap(nums[i], nums[min_index]);
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

    SelectionSort(nums);
    cout << "排序之后:" << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}
