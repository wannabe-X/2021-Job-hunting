/*
 * @Description: 数字在升序数组中出现的次数。使用二分查找左右边界
 * @Author: Mr. Lee
 * @Date: 2021-06-29 22:10:56
 * @LastEditTime: 2021-06-29 22:25:22
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

int leftbound(vector<int> data, int target)
{
    int i = 0, j = data.size();
    while (i < j)
    {
        int mid = i + (j - i) / 2;
        if (data[mid] < target)
            i = mid + 1;
        else
            j = mid;
    }
    return i;
}

int rightbound(vector<int> data, int target)
{
    int i = 0, j = data.size();
    while (i < j)
    {
        int mid = i + (j - i) / 2;
        if (data[mid] > target)
            j = mid;
        else
            i = mid + 1;
    }
    return i - 1;
}

int GetNumberOfK(vector<int> data, int k)
{
    return rightbound(data, k) - leftbound(data, k) + 1;
}

int main()
{
    // 测试用例
    // vector<int> data = {1, 2, 3, 3, 3, 3, 4, 5};
    // int k = 3;

    int idx = 0, n, k;
    cin >> n >> k;
    vector<int> data(n);
    while (idx < n && cin >> data[idx++])
        ;
    int ans = GetNumberOfK(data, k);
    cout << ans << endl;

    return 0;
}
