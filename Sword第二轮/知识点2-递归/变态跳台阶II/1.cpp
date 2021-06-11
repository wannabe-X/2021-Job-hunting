/*
 * @Description: 剑指offer-变态跳台阶II
 * @Author: Mr. Lee
 * @Date: 2021-06-11 09:38:39
 * @LastEditTime: 2021-06-11 10:09:35
 * @LastEditors: Mr. Lee
 */

/*
    关于本题，前提是n个台阶会有一次n阶的跳法。
        f(n) = f(n-1) + f(n-2) + f(n-3) + ... + f(n-(n-1)) + f(n-n) 
*/

#include <iostream>

using namespace std;

int jumpFloorII(int number)
{
    int f_0 = 1, f_1 = 0;
    for (int i = 1; i <= number; i++)
    {
        f_1 += f_0;
        f_0 = f_1;
    }

    return f_1;
}

int main()
{
    // 测试用例
    // int number = 5;
    // int ans = jumpFloorII(number);

    int number;
    cin >> number;
    int ans = jumpFloorII(number);
    cout << ans << endl;
    return 0;
}
