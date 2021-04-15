#include <iostream>

using namespace std;

int numWays(int n)
{
    if (n <= 1)
        return 1;
    return (numWays(n - 1) + numWays(n - 2)) % 1000000007;
}

int main(void)
{
    int n = 7;
    int ans = numWays(n);
    cout << ans << endl;
    return 0;
}