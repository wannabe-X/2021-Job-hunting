#include <iostream>
using namespace std;

int add(int a, int b)
{
    int sum, carry;
    do
    {
        sum = (a ^ b);
        // cout << "sum:" << sum << endl;
        carry = (unsigned int)(a & b) << 1;
        // cout << "carry:" << ((unsigned int)(a & b) << 1) << endl;
        a = sum;
        b = carry;
    } while (b != 0);

    return a;
}

int main(void)
{
    int n = -1, m = 2;
    int ans = add(n, m);
    cout << ans << endl;
    return 0;
}