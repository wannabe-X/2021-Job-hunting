/*
 * @Description: 数字在升序数组中出现的次数。常规思路，遍历
 * @Author: Mr. Lee
 * @Date: 2021-06-29 22:10:56
 * @LastEditTime: 2021-06-29 22:25:51
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

int GetNumberOfK(vector<int> data, int k)
{
    int count = 0;
    for (int num : data)
    {
        if (num == k)
            count++;
    }

    return count;
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
