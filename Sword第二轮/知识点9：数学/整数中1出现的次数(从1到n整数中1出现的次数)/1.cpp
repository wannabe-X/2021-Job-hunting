/*
 * @Description: 整数中1出现的次数（从1到n整数中1出现的次数）
 * @Author: Mr. Lee
 * @Date: 2021-06-23 23:01:45
 * @LastEditTime: 2021-06-23 23:31:12
 * @LastEditors: Mr. Lee
 */

#include <iostream>

using namespace std;

int getones(int num)
{
    int ones = 0;
    while (num)
    {
        if (num % 10 == 1)
            ones++;
        num /= 10;
    }

    return ones;
}

int NumberOf1Between1AndN_Solution(int n)
{
    int numofone = 0;
    for (int i = 1; i < n + 1; i++)
    {
        numofone += getones(i);
    }

    return numofone;
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
