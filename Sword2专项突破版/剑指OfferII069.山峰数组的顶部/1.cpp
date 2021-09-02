/*
 * @Description: 剑指 Offer II 069. 山峰数组的顶部
 * @Author: Mr. Lee
 * @Date: 2021-09-02 11:05:49
 * @LastEditTime: 2021-09-02 11:20:47
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{
    int left = 1, right = arr.size() - 2;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            return mid;
        else if (arr[mid] > arr[mid - 1])
            left = mid + 1;
        else if (arr[mid] < arr[mid - 1])
            right = mid - 1;
    }

    return -1;
}

int main(void)
{
    vector<int> arr = {3, 5, 3, 2, 0};
    int ans = peakIndexInMountainArray(arr);
    cout << ans << endl;

    return 0;
}