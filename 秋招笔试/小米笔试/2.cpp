/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-01 18:40:35
 * @LastEditTime: 2021-09-01 20:25:31
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int func(int n)
{
    int f = 0;
    for (int i = 2; i <= n; i++)
        f = (f + 3) % i;

    return f + 1;
}

int main(void)
{
    int n;
    cin >> n;
    int ans = func(n);
    cout << ans;

    return 0;
}