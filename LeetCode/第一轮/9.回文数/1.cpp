#include <iostream>

using namespace std;

bool isPalindrome(int x)
{
    if(!x) return true;
    if (x < 0 || x % 10 == 0)
        return false;
    int reverse = 0;
    while (x > reverse)
    {
        reverse = reverse * 10 + x % 10;
        x /= 10;
    }

    return x == reverse || x == reverse / 10;
}

int main(void)
{
    int x = 1;
    bool ans = isPalindrome(x);
    cout << ans << endl;
    return 0;
}