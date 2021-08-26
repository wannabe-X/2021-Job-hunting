/*
 * @Description: 归并排序
 * @Author: Mr. Lee
 * @Date: 2021-08-26 15:53:00
 * @LastEditTime: 2021-08-26 18:45:25
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void print(vector<int> &arr, bool isBefore = true)
{
    if (isBefore)
    {
        cout << "排序之前:" << endl;
        for (int num : arr)
        {
            cout << num << " ";
        }
    }
    else
    {
        cout << "排序之后:" << endl;
        for (int num : arr)
        {
            cout << num << " ";
        }
    }

    cout << endl;
}

// 冒泡排序
void bubbleSort(vector<int> &arr)
{
    // 比较相邻的两个元素，小的在后，则交换
    // 一轮过后，第len个数据最大，放到最后

    for (int i = 0; i < arr.size() - 1; i++) // 需要比较的轮数
    {
        // 每一轮 01 12 23 ... 89 i=0
        // 每二轮 01 12 23 ... 78 i=1
        // 每三轮 01 12 23 ... 67 i=2
        // ....
        // 每九轮 01 i=8
        // 所以 j的取值范围是[0,arr.size()-i-1) 左闭右开区间
        for (int j = 0; j < arr.size() - i - 1; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                // 交换，将大数移至最后
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

// 选择排序：从待排数组[0,arr.size()-1]中选择最小的与第一个元素交换
void selectSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++) // 需要比较的轮数
    {
        int minIndex = i;
        for (int j = i + 1; j < arr.size(); j++) // 从arr[i+1,arr.size()-1] 寻找最小的元素下标
        {
            minIndex = (arr[minIndex] > arr[j]) ? j : minIndex;
            // if (arr[minIndex] > arr[j])
            // {
            //     minIndex = j;
            // }
        }

        // 交换 minIndex对应的元素与i对应的元素下标进行交换
        if (minIndex != i)
        {
            int tmp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = tmp;
        }
    }
}

// 插入排序
void insertSort(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++) // 从第二个数据开始
    {
        int tmp = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > tmp)
        {
            arr[j + 1] = arr[j]; // 依次往后覆盖
            j--;
        }

        arr[j + 1] = tmp; // 注意要覆盖的位置是j+1
    }
}

// 希尔排序
void shellSort(vector<int> &arr)
{
    int step = arr.size() / 2;
    while (step)
    {
        for (int i = step; i < arr.size(); i++) // 从第step个数据开始
        {
            // 每个组内做插入排序
            int tmp = arr[i];
            int j = i - step;

            while (j >= 0 && arr[j] > tmp)
            {
                arr[j + step] = arr[j]; // 依次往后覆盖
                j -= step;
            }

            arr[j + step] = tmp; // 注意要覆盖的位置是j+1
        }

        step /= 2;
    }
}

// 快速排序
// void quickSort(vector<int> &nums)
// {
//     stack<int> s;
//     s.push(nums.size() - 1);
//     s.push(0);

//     while (!s.empty())
//     {
//         int low = s.top();
//         s.pop();
//         int high = s.top();
//         s.pop();

//         int i = low, j = high;
//         if (i >= j)
//             continue; //这一步很关键，不然无限循环

//         int pivot = nums[i];

//         while (i < j)
//         {
//             while (i < j && nums[j] >= pivot)
//                 j--;
//             nums[i] = nums[j];
//             while (i < j && nums[i] < pivot)
//                 i++;
//             nums[j] = nums[i];
//         }

//         nums[i] = pivot;

//         //从右往左，从高到低
//         s.push(high);
//         s.push(i + 1);
//         //注意存的不是begin和end，而是循环新生成的两端
//         s.push(i - 1);
//         s.push(low);
//     }

//     return;
// }

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
        int pivot = nums[i];

        while (i < j)
        {
            while (i < j && pivot <= nums[j])
            {
                j--;
            }
            nums[i] = nums[j];

            while (i < j && pivot > nums[i])
            {
                i++;
            }
            nums[j] = nums[i];
        }

        nums[i] = pivot;

        s.push(high);
        s.push(i + 1);
        s.push(i - 1);
        s.push(low);
    }
}

int main(int argc, char *argv[])
{
    vector<int> arr = {1, 9, 66, 0, 33, 5, 2, 88, 666, 233};
    print(arr);

    // 冒泡排序
    // cout << "Bubble Sort";
    // bubbleSort(arr);
    // print(arr, false);

    // 选择排序
    // cout << "Select Sort";
    // selectSort(arr);
    // print(arr, false);

    // 插入排序
    // cout << "Insert Sort";
    // insertSort(arr);
    // print(arr, false);

    // 快速排序 非递归
    cout << "Quick Sort";
    quickSort(arr);
    print(arr, false);

    return 0;
}
