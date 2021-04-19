#include <iostream>
using namespace std;

// 快速幂例子
// 如果n=10，那么n的二进制为1010
// 1010(二进制) = 0*2^(0)+1*2^(1)+0*2^(2)+1*2^(3)
// 那么 x^(10) = x^2 * x^8，也就是说把n的二进制中的1都取出来(可以利用n&1==1)来判断
// 每次取出二进制中的1可以用 n>>=1，结合n&1==1判断是否应该乘进ans中
// x^0,x^2,x^4,x^8,...可以通过x*=x循环来计算
// 注意：if ((b & 1) == 1) ans *= x; 两句代码要放到循环的起始位置
double fastPow(double x, int n)
{
    if (x == 0)
        return 0;
    long b = n;
    double ans = 1.0;

    if (b < 0)
    {
        b = -b;
        x = 1 / x;
    }

    while (b)
    {
        if (b % 2)
            ans *= x;
        x *= x;
        b /= 2;
    }

    // while (b)
    // {
    //     if ((b & 1) == 1)
    //         ans *= x;
    //     x *= x;
    //     b >>= 1;
    // }

    return ans;
}

int main(void)
{
    double x = 10;
    int n = -2;
    double ans = fastPow(x, n);
    cout << ans << endl;
    return 0;
}