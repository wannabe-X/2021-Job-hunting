/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-06-23 10:40:44
 * @LastEditTime: 2021-06-23 10:42:32
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
        n = (n & (n - 1));
        count++;
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
