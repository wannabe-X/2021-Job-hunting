/*
 * @Description:
 * @Author: Mr. Lee
 * @Date: 2021-12-13 15:39:02
 * @LastEditTime: 2021-12-13 15:40:09
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//主函数
int BFPRT(vector<int> &nums, int left, int right, int k);
//获取主元所在下标
int getPivotIndex(vector<int> &nums, int left, int right);
// Partition函数
int partition(vector<int> &nums, int left, int right, int pivotIndex);
//插入排序获取中位数下标
int getMedianByInsertionSort(vector<int> &nums, int left, int right);

int main()
{
    vector<int> array{13, 14, 15, 12, 10, 9, 8, 7, 11, 1, 5, 2, 3, 4, 6};

    int length = array.size();

    printf("原始数组为：\n");
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << "  ";
    }

    for (int k = 1; k <= length; k++)
    {
        printf("第%d小的数是：%d", k, array[BFPRT(array, 0, length - 1, k)]);
        printf("此时的数组为：\n");
        for (int i = 0; i < length; i++)
            cout << array[i] << "  ";
        cout << endl
             << "-----------------------------------------------------" << endl;
    }

    return 0;
}

int BFPRT(vector<int> &nums, int left, int right, int k)
{
    int pivotIndex = getPivotIndex(nums, left, right);
    int index = partition(nums, left, right, pivotIndex);
    if (left == right)
        return left;
    int count = index - left + 1;
    if (count == k)
        return index;
    else if (count > k)
        return BFPRT(nums, left, index - 1, k);
    else
        return BFPRT(nums, index + 1, right, k - count);
}

int getPivotIndex(vector<int> &nums, int left, int right)
{
    if (right - left + 1 <= 5)
        return getMedianByInsertionSort(nums, left, right);
    int pos = left;
    for (int i = left; i + 4 < right; i += 5)
    {
        int index = getMedianByInsertionSort(nums, i, i + 4);
        swap(nums[pos++], nums[index]);
    }
    return BFPRT(nums, left, pos, (pos - left) / 2 + left + 1);
}

int partition(vector<int> &nums, int left, int right, int pivotIndex)
{
    int i = left, j = right;
    int key = nums[pivotIndex];
    swap(nums[left], nums[pivotIndex]);
    while (i < j)
    {
        while (nums[j] >= key && i < j)
            j--;
        while (nums[i] <= key && i < j)
            i++;
        if (i < j)
            swap(nums[i], nums[j]);
    }
    swap(nums[i], nums[left]);
    return i;
}

int getMedianByInsertionSort(vector<int> &nums, int left, int right)
{
    for (int j = left + 1; j <= right; j++)
    {
        int i = j - 1;
        int curNum = nums[j];
        while (i >= left && curNum < nums[i])
        {
            nums[i + 1] = nums[i];
            i--;
        }
        nums[i + 1] = curNum;
    }
    return (right - left) / 2 + left;
}