/*
 * @Description: 233. 数字 1 的个数
 * @Author: Mr. Lee
 * @Date: 2021-08-13 09:04:22
 * @LastEditTime: 2021-08-13 22:52:05
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>

using namespace std;

int countDigitOne(int n)
{
    int res = 0;
    int low = 0, cur = n % 10, high = n / 10;
    long digit = 1;
    while (high != 0 || cur != 0)
    {
        if (cur == 0)
            res += (high * digit);
        else if (cur == 1)
            res += (high * digit + low + 1);
        else
            res += (high + 1) * digit;

        low += cur * digit;
        cur = high % 10;
        high /= 10;
        digit *= 10;
    }

    return res;
}

int main()
{
    int n = 6789;
    int ans = countDigitOne(n);
    cout << ans << endl;

    return 0;
}
