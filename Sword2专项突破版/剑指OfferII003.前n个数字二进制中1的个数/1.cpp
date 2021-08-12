/*
 * @Description: 剑指 Offer II 003. 前 n 个数字二进制中 1 的个数
 * @Author: Mr. Lee
 * @Date: 2021-08-12 11:25:35
 * @LastEditTime: 2021-08-12 11:39:49
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> countBits(int n)
{
    vector<int> res;
    for (int i = 0; i <= n; i++)
    {
        int count = 0, tmp = i;
        while (tmp)
        {
            count++;
            tmp = tmp & (tmp - 1);
        }
        res.push_back(count);
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
