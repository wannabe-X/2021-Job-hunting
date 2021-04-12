#include <iostream>
#include <cmath>

using namespace std;

int bulbSwitch(int n)
{
    return (int)sqrt(n);
}

int main(void)
{
    int n = 16;
    int ans = bulbSwitch(n);
    cout << ans << endl;
    return 0;
}