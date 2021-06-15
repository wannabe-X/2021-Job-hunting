/*
 * @Description: 852. 山脉数组的峰顶索引。使用二分查找
 * @Author: Mr. Lee
 * @Date: 2021-06-15 15:29:30
 * @LastEditTime: 2021-06-15 15:44:27
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{
    int left = 1, right = arr.size() - 2;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] > arr[mid + 1])
            right = mid;
        else
            left = mid + 1;
    }

    return left;
}

int main()
{
    // 测试用例
    // vector<int> arr = {0,10,5,2};
    // int ans = peakIndexInMountainArray(arr);
    int n, idx = 0;
    cin >> n;
    vector<int> arr(n, 0);
    while (cin >> arr[idx++] && idx < n);
    int ans = peakIndexInMountainArray(arr);
    cout << ans << endl;
    return 0;
}