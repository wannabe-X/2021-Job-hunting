/*
 * @Description: 剑指 Offer 10- I. 斐波那契数列
 * @Author: Mr. Lee
 * @Date: 2021-09-04 00:01:48
 * @LastEditTime: 2021-09-04 00:11:58
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fib(int n)
{
    if (n == 0)
        return 0;

    if (n <= 2)
        return 1;

    int pre = 1, cur = 1;
    int mod = int(1e9 + 7);

    for (int i = 3; i <= n; i++)
    {

        cur = cur + pre;
        pre = cur - pre;

        cur %= mod;
        pre %= mod;
    }

    return cur;
}

int main(void)
{
    int n = 10;
    int ans = fib(n);
    cout << ans << endl;

    return 0;
}