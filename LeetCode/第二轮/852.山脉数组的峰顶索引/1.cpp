/*
 * @Description: 852. 山脉数组的峰顶索引。直接寻找最大值及对应下标
 * @Author: Mr. Lee
 * @Date: 2021-06-15 15:18:10
 * @LastEditTime: 2021-06-15 15:44:56
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{
    int maxval = -1, idx;
    for (int i = 1; i < arr.size()-1; i++)
    {
        if (arr[i] > maxval)
        {
            maxval = arr[i];
            idx = i;
        }
    }
    return idx;
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
