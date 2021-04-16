#include <iostream>

using namespace std;

int hammingWeight(uint32_t n)
{
    int res = 0;
    while (n)
    {
        n = (n & (n - 1)); // 去掉最后一位1
        res++;
        
    }
    return res;
}

int main(void)
{
    uint32_t n = 00000000000000000000000000001011;
    int ans = hammingWeight(n);
    cout << ans << endl;
    return 0;
}