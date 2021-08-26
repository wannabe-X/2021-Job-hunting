/*
 * @Description: 堆排序
 * @Author: Mr. Lee
 * @Date: 2021-07-23 14:28:16
 * @LastEditTime: 2021-07-23 15:53:08
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void MaxHeapify(vector<int> &nums, int start, int end)
{
    // 最大堆
    // 维护以dad开始直到末尾的元素，保证dad是这所有元素里面的最大值
    int dad = start, son = dad * 2 + 1;
    while (son <= end)
    {
        // 找到所有son中的最大值
        if (son + 1 <= end && nums[son] < nums[son + 1])
            son++;
        // 如果son大于dad，那么就交换son和dad，同时维护好交换之后的堆
        if (nums[dad] < nums[son])
        {
            swap(nums[dad], nums[son]);
            dad = son;
            son = 2 * dad + 1;
        }
        else
        {
            return;
        }
    }
}

void HeapSort(vector<int> &nums)
{
    int n = nums.size();
    // 构造初始堆。将给定无序序列构造成一个大顶堆（一般升序采用大顶堆，降序采用小顶堆)。
    // 从最后一个非叶子结点开始,从左至右，从下至上进行调整。
    for (int i = n / 2 - 1; i > -1; i--)
    {
        MaxHeapify(nums, i, n - 1);
    }
    /*      将堆顶元素与末尾元素进行交换，使末尾元素最大。
     然后继续调整堆，再将堆顶元素与末尾元素交换，得到第二大元素。如此反复进行交换、重建、交换。 */
    for (int i = n - 1; i > 0; i--)
    {
        swap(nums[0], nums[i]);
        MaxHeapify(nums, 0, i - 1);
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

    HeapSort(nums);
    cout << "排序之后:" << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}
