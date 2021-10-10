/*
 * @Description: 博弈游戏
 * @Author: Mr. Lee
 * @Date: 2021-10-10 09:52:00
 * @LastEditTime: 2021-10-10 13:08:06
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(void)
{
    int n;
    double ans = 0.0;
    cin >> n;
    if (n % 2)
        ans = double(n / 2 + 1) / n;
    else
        ans = 0.5;

    printf("%.5f", ans);

    return 0;
}