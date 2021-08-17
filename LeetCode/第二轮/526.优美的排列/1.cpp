/*
 * @Description: 526. 优美的排列
 * @Author: Mr. Lee
 * @Date: 2021-08-16 00:19:45
 * @LastEditTime: 2021-08-16 00:36:54
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>

using namespace std;

int countArrangement(int n)
{
    vector<int> f(1 << n);
    f[0] = 1;
    for (int mask = 1; mask < (1 << n); mask++)
    {
        int num = __builtin_popcount(mask);
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i) && (num % (i + 1) == 0 || (i + 1) % num == 0))
            {
                f[mask] += f[mask ^ (1 << i)];
            }
        }
    }
    return f[(1 << n) - 1];
}

int main()
{
    int n = 2;
    int ans = countArrangement(n);
    cout << ans << endl;
    
    return 0;
}