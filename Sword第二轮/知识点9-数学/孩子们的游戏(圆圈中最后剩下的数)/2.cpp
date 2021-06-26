/*
 * @Description: 剑指 Offer 62. 圆圈中最后剩下的数字。动态规划法
 * @Author: Mr. Lee
 * @Date: 2021-06-24 15:35:32
 * @LastEditTime: 2021-06-26 15:06:21
 * @LastEditors: Mr. Lee
 */

/*
    数学推导递推公式，然后使用动态规划的思路求解
*/

#include <iostream>
#include <vector>

using namespace std;

int LastRemaining_Solution(int n, int m)
{
    if (n <= 0)
        return -1;

    int f = 0;
    for (int i = 2; i != n + 1; ++i)
    {
        f = (m + f) % i;
    }
    return f;
}

int main()
{
    // 测试用例
    // int n = 5;
    // int m = 3;

    int n;
    int m;
    cin >> n >> m;
    int ans = LastRemaining_Solution(n, m);
    cout << ans << endl;

    return 0;
}