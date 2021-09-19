/*
 * @Description: 650. 只有两个键的键盘
 * @Author: Mr. Lee
 * @Date: 2021-09-19 11:22:30
 * @LastEditTime: 2021-09-19 11:37:32
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minSteps(int n)
{
    vector<int> f(n + 1);
    for (int i = 2; i <= n; ++i)
    {
        f[i] = INT_MAX;
        for (int j = 1; j * j <= i; ++j)
        {
            if (i % j == 0)
            {
                f[i] = min(f[i], f[j] + i / j);
                f[i] = min(f[i], f[i / j] + j);
            }
        }
    }
    return f[n];
}

int main(void)
{
    int n = 3;
    int ans = minSteps(n);
    cout << ans << endl;

    return 0;
}