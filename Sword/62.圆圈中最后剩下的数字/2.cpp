#include <iostream>

using namespace std;

int lastRemaining(int n, int m)
{
    int f = 0;
    for (int i = 2; i <= n; ++i)
    {
        f = (m + f) % i;
    }
    return f;
}

int main(void)
{
    int n = 5, m = 3;
    int ans = lastRemaining(n, m);
    cout << ans << endl;
    return 0;
}