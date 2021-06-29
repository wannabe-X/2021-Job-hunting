/*
 * @Description: 数组中只出现一次的两个数字。使用位运算
 * @Author: Mr. Lee
 * @Date: 2021-06-29 23:06:37
 * @LastEditTime: 2021-06-29 23:56:54
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

vector<int> FindNumsAppearOnce(vector<int> &array)
{
    int res = 0, m = 1;
    int res1 = 0, res2 = 0;
    for (int num : array)
    {
        res ^= num;
    }

    while ((m & res) == 0)
        m <<= 1;

    for (int num : array)
    {
        cout << num << endl;
        if (num & m)
            res1 ^= num;
        else
            res2 ^= num;
    }

    if (res1 > res2)
    {
        swap(res1, res2);
    }

    return {res1, res2};
}

int main()
{
    // 测试用例
    vector<int> array = {1, 4, 1, 6};

    // int n, idx = 0;
    // cin >> n;
    // vector<int> array(n);
    // while (idx < n && cin >> array[idx++])
    //     ;
    vector<int> ans = FindNumsAppearOnce(array);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}
