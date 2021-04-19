#include <iostream>
#include <math.h>

using namespace std;

// 解法1 利用公式计算 pow(x,n) = exp(n*log(x)),x>0
double myPow(double x, int n)
{
    if (x == 0)
        return 0;

    double ans = exp(n * log(abs(x)));
    if (x < 0 && n % 2) ans *= -1;

    return ans;
}

int main(void)
{
    double x = 2;
    int n = 0;
    double ans = myPow(x, n);
    cout << ans << endl;
    return 0;
}