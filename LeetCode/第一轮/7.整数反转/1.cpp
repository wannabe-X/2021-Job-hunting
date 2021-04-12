#include <iostream>
#include <cmath>

using namespace std;

int reverse(int x)
{
    if (x == 0)
        return 0;
    int num = 0;
    while (x)
    {
        int pop = x % 10;
        // 整数型的范围 [-2^31,2^31-1] => [-2147483648,2147483647]
        if (num > INT_MAX / 10 || (num == INT_MAX / 10) && pop > 7)
            return 0;
        if (num < INT_MIN / 10 || (num == INT_MIN / 10) && pop < -8)
            return 0;
        num = num * 10 + pop;
        x /= 10;
    }
    return num = (x >= 0) ? num : (~num) + 1;
}

int main()
{
    int num = 1234567879;
    int ans = reverse(num);
    cout << ans << endl;
}