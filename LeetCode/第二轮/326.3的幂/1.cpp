/*
 * @Description: 326. 3的幂
 * @Author: Mr. Lee
 * @Date: 2021-09-23 10:24:00
 * @LastEditTime: 2021-09-23 10:32:59
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPowerOfThree(int n)
{
    if (n <= 0)
        return false;

    return (log10(n) / log10(3) + 0.0) - int(log10(n) / log10(3)) == 0.0;
}

int main(void)
{
    int n = -3;
    bool ans = isPowerOfThree(n);
    cout << ans << endl;

    return 0;
}