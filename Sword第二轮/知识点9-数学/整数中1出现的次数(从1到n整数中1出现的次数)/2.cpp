/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-06-23 23:30:07
 * @LastEditTime: 2021-06-23 23:31:21
 * @LastEditors: Mr. Lee
 */

#include <iostream>

using namespace std;

int NumberOf1Between1AndN_Solution(int n)
{
    long digit = 1, res = 0;
    int high = n / 10, cur = n % 10, low = 0;
    while (high != 0 || cur != 0)
    {
        if (cur == 0)
            res += (high * digit);
        else if (cur == 1)
            res += (high * digit + low + 1);
        else
            res += (high + 1) * digit;

        low += (cur * digit);
        cur = high % 10;
        high /= 10;
        digit *= 10;
    }
    return res;
}

int main()
{
    // 测试用例
    // int n = 387;

    int n;
    cin >> n;
    int ans = NumberOf1Between1AndN_Solution(n);
    cout << ans << endl;

    return 0;
}
