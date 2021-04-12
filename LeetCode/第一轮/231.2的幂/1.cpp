#include <iostream>
#include <bitset>
using namespace std;

bool isPowerOfTwo(int n)
{
    return n > 0 && (n & (n - 1)) == 0;
}

int main(void)
{
    int n = 16;
    bool ans = isPowerOfTwo(n);
    cout << boolalpha << ans << endl;
}