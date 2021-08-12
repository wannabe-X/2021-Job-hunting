/*
 * @Description: 剑指 Offer II 003. 前 n 个数字二进制中 1 的个数
 * @Author: Mr. Lee
 * @Date: 2021-08-12 11:25:35
 * @LastEditTime: 2021-08-12 11:44:44
 * @LastEditors: Mr. Lee
 */

// 参考解法

#include <iostream>
#include <vector>

using namespace std;

vector<int> countBits(int n)
{
    vector<int> res(n + 1);
    for (int i = 0; i <= n; i++)
    {
        if (i & 1)
            res[i] = res[i - 1] + 1;
        else
            res[i] = res[i >> 1];
    }

    return res;
}

int main()
{
    int n = 5;
    vector<int> ans = countBits(n);
    for (auto &x : ans)
        cout << x << " ";

    return 0;
}
