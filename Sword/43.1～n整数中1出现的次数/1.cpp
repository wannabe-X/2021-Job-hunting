#include <iostream>

using namespace std;

int countDigitOne(int n)
{
    int digit = 1, res = 0;
    int high = n / 10, cur = n % 10, low = 0;
    while (high != 0 || cur != 0)
    {
        if (cur == 0)
            res += (high * digit);
        else if (cur == 1)
            res += (high * digit + low + 1);
        else
            res += (high + 1) * digit;

        low += (cur * digit);
        cur = high % 10;
        high /= 10;
        digit *= 10;
    }
    return res;
}

int main(void)
{
    int n = 100;
    int ans = countDigitOne(n);
    cout << ans << endl;
    return 0;
}