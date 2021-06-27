/*
 * @Description: 剪绳子
 * @Author: Mr. Lee
 * @Date: 2021-06-27 21:55:23
 * @LastEditTime: 2021-06-27 22:17:33
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>

using namespace std;

int getMaxVal(int number, int m)
{
    int maxVal = 1;
    for (int i = m; i > 0; i--)
    {
        int avg = number / i;
        maxVal *= avg;
        number -= avg;
    }

    return maxVal;
}

int cutRope(int number)
{
    int res = -1;
    for (int m = 2; m <= number; m++)
    {
        res = max(res, getMaxVal(number, m));
    }

    return res;
}

int main()
{
    // 测试用例
    // int number = 8;

    int number;
    cin >> number;
    int ans = cutRope(number);
    cout << ans << endl;

    return 0;
}
