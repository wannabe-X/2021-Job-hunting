#include <iostream>
#include <math.h>

using namespace std;

// 解法2 参考解法 利用快速幂来进行求解
double myPow(double x, int n)
{
    if (x == 0)
        return 0;
    long b = n;
    double res = 1.0;

    // n<0,b<0时 pow(x,n) = pow(1/x,-n)
    if (b < 0)
    {
        x = 1 / x;
        b = -b;
    }

    while (b)
    {
        if (b & 1 == 1)
            res *= x;
        x *= x;
        b >>= 1; // b = b>>=1
    }

    return res;
}

int main(void)
{
    double x = 10;
    int n = -2;
    double ans = myPow(x, n);
    cout << ans << endl;
    return 0;
}