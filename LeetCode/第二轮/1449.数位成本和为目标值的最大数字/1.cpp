/*
 * @Description: 1449. 数位成本和为目标值的最大数字。
 * @Author: Mr. Lee
 * @Date: 2021-06-12 20:34:35
 * @LastEditTime: 2021-06-12 22:56:49
 * @LastEditors: Mr. Lee
 */

/*
    动态规划：
        定义二维数组 dp，其中 dp[i+1][j] 表示使用前 i 个数位且花费总成本【恰好】为 j 时的最大位数.
        注意初始值。
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

string largestNumber(vector<int> &cost, int target)
{
    string res;
    vector<vector<int>> dp(10, vector<int>(target + 1, INT_MIN));
    vector<vector<int>> from(10, vector<int>(target + 1, 0));
    dp[0][0] = 0;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < target + 1; j++)
        {
            if (j < cost[i])
            {
                dp[i + 1][j] = dp[i][j];
                from[i + 1][j] = j; // 没有选第i个数字
            }
            if (j >= cost[i])
            {
                if (dp[i][j] > dp[i + 1][j - cost[i]] + 1)
                {
                    dp[i + 1][j] = dp[i][j];
                    from[i + 1][j] = j;
                }
                else
                {
                    dp[i + 1][j] = dp[i + 1][j - cost[i]] + 1;
                    from[i + 1][j] = j - cost[i]; // 选了第i个数字
                }
            }
        }
    }

    if (dp[9][target] < 0)
    {
        return "0";
    }

    string ans;
    int i = 9, j = target;
    while (i > 0)
    {
        if (j == from[i][j]) // 如果j == from[i][j]，说明第i位数字没有选择
        {
            --i;
        }
        else
        {
            ans += '0' + i; // 如果j != from[i][j]，则选了第i个数字，记录
            j = from[i][j]; // 然后j = from[i][j]，考察使用前i个数字，成本为j的时候，是从哪个成本【j - cost[i]】转移来的
        }
    }

    return ans;
}

int main()
{
    // 测试用例
    vector<int> cost = {4, 3, 2, 5, 6, 7, 2, 5, 5};
    int target = 9;
    //
    string ans = largestNumber(cost, target);
    cout << ans << endl;

    return 0;
}
