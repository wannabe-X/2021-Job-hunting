/*
 * @Description: 数值的整数次方
 * @Author: Mr. Lee
 * @Date: 2021-06-23 17:48:45
 * @LastEditTime: 2021-06-23 17:56:23
 * @LastEditors: Mr. Lee
 */

#include <iostream>

using namespace std;

double Power(double base, int exponent)
{
    if (exponent < 0)
        base = 1 / base;
    double res = 1.0;
    exponent = exponent > 0 ? exponent : -exponent;

    while (exponent--)
    {
        res *= base;
    }

    return res;
}

int main()
{
    // 测试用例
    // double base = 2;
    // int exponent = -2;
    // double ans = Power(base, exponent);
    // cout << ans << endl;

    double base;
    int exponent;
    cin >> base >> exponent;
    double ans = Power(base, exponent);
    cout << ans << endl;

    return 0;
}