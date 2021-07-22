/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-07-22 16:58:58
 * @LastEditTime: 2021-07-22 17:26:55
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

void BubbleSort(vector<int> &nums)
{
    int len = nums.size();
    int flag = 1; // 标志位，如果存在数字交换，就置1
    for (int i = 0; i < len - 1 && flag; i++)
    {
        flag = 0; // 如果不存在数字交换，就说明已经排好序
        for (int j = len - 1; j > i; j--)
        {
            // 顺序，从小往大排序
            // 第一轮结束后，第一个元素就是数组中最小的元素
            if (nums[j - 1] > nums[j])
            {
                // 将小的数据交换到前面，冒泡
                swap(nums[j], nums[j - 1]);
                flag = 1;
            }
        }
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

    BubbleSort(nums);
    cout << "排序之后:" << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}