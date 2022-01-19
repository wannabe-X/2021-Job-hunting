/*
 * @Description: 1716. 计算力扣银行的钱
 * @Author: Mr. Lee
 * @Date: 2022-01-19 10:56:19
 * @LastEditTime: 2022-01-19 11:39:34
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int totalMoney(int n)
{
    int m1 = n / 7, m2 = n % 7;
    return 24.5 * m1 + 3.5 * m1 * m1 + m1 * m2 + 0.5 * m2 + 0.5 * m2 * m2;
}

int main(int argc, char *argv[])
{
    int n = 5;
    int ans = totalMoney(n);
    cout << ans << endl;

    return 0;
}