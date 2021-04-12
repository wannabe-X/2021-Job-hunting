#include <iostream>

using namespace std;

bool canWinNim(int n)
{
    return n % 4 != 0;
}

int main(void)
{
    int n = 1;
    bool ans = canWinNim(n);
    cout << boolalpha << ans << endl;
    return 0;
}