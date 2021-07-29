/*
 * @Description: 数值的整数次方
 * @Author: Mr. Lee
 * @Date: 2021-07-29 15:36:53
 * @LastEditTime: 2021-07-29 16:06:55
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>

using namespace std;

bool equal(double num1, double num2)
{
    if (abs(num1 - num2) < 0.0000001)
        return true;
    return false;
}

double PowerWithunsignedExponent(double base, unsigned int exponent)
{
    if (exponent == 0)
        return 1.0;
    if (exponent == 1)
        return base;

    double result = PowerWithunsignedExponent(base, exponent >> 1);
    result *= result;
    if (exponent & 1 == 1)
        result *= base;

    return result;
}

double Power(double base, int exponent)
{
    if (equal(base, 0.0) && exponent < 0)
        return 0.0;

    unsigned int absExponent = (unsigned int)exponent;
    if (exponent < 0)
    {
        base = 1 / base;
        absExponent = (unsigned int)(-exponent);
    }

    // double res = 1.0;

    // for (int i = 1; i <= absExponent; i++)
    // {
    //     res *= base;
    // }

    double res = PowerWithunsignedExponent(base, absExponent);

    return res;
}

int main()
{
    double base = -2.0;
    int exponent = -3;
    double ans = Power(base, exponent);
    cout << ans << endl;

    return 0;
}
