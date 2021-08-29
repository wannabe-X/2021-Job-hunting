/*
 * @Description: 1588. 所有奇数长度子数组的和
 * @Author: Mr. Lee
 * @Date: 2021-08-29 00:27:26
 * @LastEditTime: 2021-08-29 00:54:19
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 暴力解法
// int getLenSum(vector<int> &arr, int length)
// {
//     int sum = 0;
//     for (int i = 0; i < arr.size() - length + 1; i++)
//     {
//         for (int j = 0; j < length; j++)
//         {
//             sum += arr[i + j];
//         }
//     }

//     return sum;
// }

// int sumOddLengthSubarrays(vector<int> &arr)
// {
//     int res = 0;
//     for (int i = 1; i <= arr.size(); i += 2)
//     {
//         res += getLenSum(arr, i);
//     }

//     return res;
// }

// 前缀和
int sumOddLengthSubarrays(vector<int> &arr)
{
    int res = 0;

    vector<int> v;
    v.push_back(0);

    for (auto &num : arr)
    {
        v.push_back(v.back() + num);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        for (int len = 1; i + len < arr.size() + 1; len += 2)
        {
            res += (v[i + len] - v[i]);
        }
    }

    return res;
}

int main(void)
{
    vector<int> arr = {1, 2};
    int ans = sumOddLengthSubarrays(arr);
    cout << ans << endl;

    return 0;
}