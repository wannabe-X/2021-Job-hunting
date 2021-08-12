/*
 * @Description: 剑指 Offer II 001. 整数除法
 * @Author: Mr. Lee
 * @Date: 2021-08-11 15:42:55
 * @LastEditTime: 2021-08-11 20:04:53
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int Divisor(int a, int b)
{
    int ans = 0;

    while (a <= b)
    {
        int multiple = 1;
        int tmpb = b;

        while (tmpb >= a - tmpb)
        {
            multiple *= 2;
            tmpb *= 2;
        }

        a -= tmpb;
        ans += multiple;
    }

    return ans;
}

int divide(int a, int b)
{
    if (a == 0)
        return 0;
    if (b == 1)
        return a;
    if (b == -1)
        return a == INT_MIN ? INT_MAX : -a;

    bool isNeg = false;

    isNeg = (a > 0 && b < 0) || (a < 0 && b > 0);

    a = (a > 0 ? -a : a);
    b = (b > 0 ? -b : b);

    // a b均为负数
    int ans = Divisor(a, b);

    if (!isNeg)
        return (ans == INT_MAX) ? INT_MAX : ans;

    return -ans;
}

int main()
{
    int a, b;
    cin >> a >> b;
    int ans = divide(a, b);
    cout << ans << endl;

    return 0;
}
