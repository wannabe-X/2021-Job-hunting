/*
 * @Description: 剑指 Offer II 072. 求平方根
 * @Author: Mr. Lee
 * @Date: 2021-09-03 09:38:59
 * @LastEditTime: 2021-09-03 10:06:29
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mySqrt(int x)
{
    int left = 1, right = x; // 左闭右闭区间
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (mid <= x / mid && (mid + 1) > x / (mid + 1))
            return mid;
        else if (mid <= x / mid)
            left = mid + 1;
        else if (mid > x / mid)
            right = mid - 1;
    }

    return 0;
}

int main(void)
{
    int x = 16;
    int ans = mySqrt(x);
    cout << ans << endl;

    return 0;
}