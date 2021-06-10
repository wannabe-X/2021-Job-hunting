/*
 * @Description: 剑指 Offer 10- II	青蛙跳台阶问题  
 * @Author: Mr. Lee
 * @Date: 2021-06-10 22:52:36
 * @LastEditTime: 2021-06-10 23:13:51
 * @LastEditors: Mr. Lee
 */

/*
    动态规划法：
        考虑如果有n个台阶，如何计算dp[n];
        可以知道：青蛙一次可以跳一步或者两步。那么dp[n]可以由状态dp[n-1]和dp[n-2]得到
        因为，青蛙要跳到第n层，只有两种方法，要么从第n-1层一步就跳上去；要么从n-2层两步跳上去
    所以，状态转移方程为：dp[n] = d[n-1] + d[n-2]
    初始条件dp[1] = 1,dp[2] = 2
*/
#include <iostream>
#include <vector>

using namespace std;

int jumpFloor(int number)
{
    // 定义dp[n] 表示青蛙跳到第n+1层的方案数
    // 最终返回结果为dp[number]
    vector<int> dp(number, 0);
    dp[0] = 1, dp[1] = 2;

    for (int i = 2; i < number; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[number - 1];
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
