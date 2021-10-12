/*
 * @Description: 29. 两数相除
 * @Author: Mr. Lee
 * @Date: 2021-10-12 09:33:01
 * @LastEditTime: 2021-10-12 09:53:26
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Divisor(long a, long b)
{
    long res = 0;
    while (a >= b)
    {
        long tmpb = b, multiplie = 1;
        while (a >= 2 * tmpb)
        {
            tmpb *= 2;
            multiplie *= 2;
        }
        res += multiplie;
        a -= tmpb;
    }

    return res;
}

int divide(int dividend, int divisor)
{
    if (dividend == 0)
        return 0;
    if (divisor == 1)
        return dividend;
    if (divisor == -1)
        return dividend == INT_MIN ? INT_MAX : -dividend;

    bool isNeg = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);
    long a = dividend, b = divisor;
    a = a > 0 ? a : -a;
    b = b > 0 ? b : -b;

    int res = Divisor(a, b);

    if (!isNeg)
        return res == INT_MAX ? INT_MAX : res;

    return -res;
}

int main(void)
{
    int a = 5, b = -2;
    int ans = divide(a, b);
    cout << ans << endl;

    return 0;
}