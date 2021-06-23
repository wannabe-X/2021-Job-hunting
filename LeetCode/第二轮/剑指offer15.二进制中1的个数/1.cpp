/*
 * @Description: 剑指offer15.二进制中1的个数
 * @Author: Mr. Lee
 * @Date: 2021-06-23 09:29:50
 * @LastEditTime: 2021-06-23 10:39:47
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <stdint.h>

using namespace std;

int hammingWeight(uint32_t n)
{
    int count = 0;
    while (n)
    {
        count += (n & 1);
        n = n >> 1;
    }

    return count;
}

int main()
{
    uint32_t n = 11111111111111111111111111111101;
    int ans = hammingWeight(n);
    cout << ans << endl;

    return 0;
}
