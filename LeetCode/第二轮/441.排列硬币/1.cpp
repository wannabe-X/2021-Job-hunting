/*
 * @Description: 441. 排列硬币
 * @Author: Mr. Lee
 * @Date: 2021-10-10 17:07:40
 * @LastEditTime: 2021-10-10 17:24:54
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int arrangeCoins(int n)
{
    return int((sqrt((long long)8 * n + 1) - 1) / 2);
}

int main(void)
{
    int n = INT_MAX;
    int ans = arrangeCoins(n);
    cout << ans << endl;

    return 0;
}