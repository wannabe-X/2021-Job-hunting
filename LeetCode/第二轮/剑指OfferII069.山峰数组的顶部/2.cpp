/*
 * @Description: 剑指 Offer II 069. 山峰数组的顶部
 * @Author: Mr. Lee
 * @Date: 2021-10-14 10:36:36
 * @LastEditTime: 2021-10-14 11:04:17
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{
    int left = 0, right = arr.size() - 2;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] > arr[mid + 1])
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return left;
}

int main(void)
{
    vector<int> arr = {1, 3, 5, 4, 2};
    int ans = peakIndexInMountainArray(arr);
    cout << ans << endl;
    return 0;
}