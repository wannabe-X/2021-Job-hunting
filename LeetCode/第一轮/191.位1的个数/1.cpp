#include <iostream>

using namespace std;

int hammingWeight(uint32_t n)
{
    int res = 0;
    while (n)
    {
        cout << n << endl;
        n = n & (n - 1);
        res++;
    }
    return res;
}

int main(void)
{
    uint32_t num = 0101;
    int ans = hammingWeight(num);
    cout << ans << endl;
}