/*
 * @Description: 397. 整数替换
 * @Author: Mr. Lee
 * @Date: 2021-11-20 23:25:08
 * @LastEditTime: 2021-11-20 23:41:37
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int integerReplacement(int n)
{
    if (n == 1)
        return 0;
    if (n % 2 == 0)
        return 1 + integerReplacement(n / 2);

    return 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
}

int main(int argc, char **argv)
{
    int n = 8;
    int ans = integerReplacement(n);
    cout << ans << endl;

    return 0;
}