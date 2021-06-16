/*
 * @Description: 矩形覆盖 动态规划法
 * @Author: Mr. Lee
 * @Date: 2021-06-16 16:31:14
 * @LastEditTime: 2021-06-16 17:34:02
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

/*
    状态转移方程为：f(n) = f(n-1) + f(n-2)
*/

int rectCover(int number)
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
    // int number = 4;
    // int ans = rectCover(number);

    // 实际输入
    int number;
    cin >> number;
    int ans = rectCover(number);
    cout << ans << endl;

    return 0;
}

