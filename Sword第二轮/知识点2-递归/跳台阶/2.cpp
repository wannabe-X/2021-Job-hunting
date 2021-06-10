/*
 * @Description: 剑指 Offer 10- II	青蛙跳台阶问题 状态压缩
 * @Author: Mr. Lee
 * @Date: 2021-06-10 22:52:36
 * @LastEditTime: 2021-06-10 23:11:31
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;


// 状态压缩
// 其实由状态转移方程可以发现，青蛙跳台阶问题其实就是斐波拉契数列的问题，只不过初始值不同
// 斐波拉契数列的初始值为1,1 前两项
// 青蛙跳台阶问题的初始值为1,2 前两项
int jumpFloor(int number)
{
    if (number < 3)
        return number;
    int a = 1, b = 2;
    for (int i = 3; i <= number; i++)
    {
        b = a + b;
        a = b - a;
    }
    return b;
}

int main()
{
    // 测试用例
    // int number = 5;
    // int ans = jumpFloor(number);

    int number;
    cin >> number;
    int ans = jumpFloor(number);
    cout << ans << endl;
    return 0;
}

