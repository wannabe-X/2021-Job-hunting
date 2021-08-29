/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-08-29 10:51:04
 * @LastEditTime: 2021-08-29 11:49:20
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int func(int a, int b)
{
    int count = 0;
    int sum = 0;
    int num = abs(a - b);

    int i = 1;
    for (; num >= sum; i++)
    {
        sum += i;
        count++;
    }

    count--;
    sum -= (i - 1);
    count += (num - sum) * 2;

    return count;
}

int main(void)
{
    int m = 1e9 - 1, n = 1e9;
    int ans = func(n, m);
    cout << ans << endl;

    return 0;
}