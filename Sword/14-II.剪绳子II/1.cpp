#include <iostream>
#include <cmath>

using namespace std;

int cuttingRope(int n)
{
    if (n <= 2)
        return 1;
    if (n == 3)
        return 2;
    int timeOf3 = n / 3;
    // 就是求3x+2y=n的整数解 并且保证x尽可能大
    // 已知 n % 3 等于 0或1或2
    // 若n % 3 = 0或2 那么x y都是整数解
    // 若n % 3 = 1  那么y将无法得到整数解，此时只能从x中拿出一个3，使得(3+1)/2等于y=2
    if (n % 3 == 1)
        timeOf3--;
    int timeOf2 = (n - 3 * timeOf3) / 2;

    long res = 1;

    for (int i = 0; i < timeOf3; res = res * 3 % 1000000007, i++)
        ;

    for (int i = 0; i < timeOf2; res = res * 2 % 1000000007, i++)
        ;

    return res;
}

int main(void)
{
    int n = 1000;
    int ans = cuttingRope(n);
    cout << ans << endl;
    return 0;
}