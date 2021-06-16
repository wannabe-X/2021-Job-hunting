/*
 * @Description: 矩形覆盖 递归法+备忘录
 * @Author: Mr. Lee
 * @Date: 2021-06-16 16:31:14
 * @LastEditTime: 2021-06-16 17:33:55
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

/*
    状态转移方程为：f(n) = f(n-1) + f(n-2)
*/

int helper(vector<int> &memo, int number)
{
    if (number <= 2)
        return number;
    if (memo[number] != 0)
        return memo[number];
    memo[number] = helper(memo, number - 1) + helper(memo, number - 2);

    return memo[number];
}

int rectCover(int number)
{
    if (number <= 3)
        return number;
    vector<int> memo(number + 1, 0);
    return helper(memo, number);
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