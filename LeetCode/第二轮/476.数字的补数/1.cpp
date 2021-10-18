/*
 * @Description: 476. 数字的补数
 * @Author: Mr. Lee
 * @Date: 2021-10-18 09:27:25
 * @LastEditTime: 2021-10-18 09:45:43
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findComplement(int num)
{
    int res = 0;
    long digit = 1;

    while (num)
    {
        res += digit * (num % 2 ? 0 : 1);
        num /= 2;
        digit *= 2;
    }

    return res;
}

int main(void)
{
    int num = 2147483647;
    int ans = findComplement(num);
    cout << ans << endl;

    return 0;
}
