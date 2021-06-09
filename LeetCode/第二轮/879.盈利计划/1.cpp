/*
 * @Description:LeetCode 879. 盈利计划。使用三维数组的形式
 * @Author: Mr. Lee
 * @Date: 2021-06-09 14:48:42
 * @LastEditTime: 2021-06-09 17:11:21
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
{
    int len = group.size(), MOD = (int)1e9 + 7;
    /*
        res[i][j][k] 表示在前i项工作中，选择了j名员工，获得利润至少为k的方案数。
        转换为01背包问题，不过限制条件有两个，一个是员工数量，另外一个是利润。所以使用三维数组
    */
    vector<vector<vector<int>>> res(len + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1, 0)));
    res[0][0][0] = 1;

    for (int i = 1; i < len + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            for (int k = 0; k < minProfit + 1; k++)
            {
                res[i][j][k] = res[i - 1][j][k];
                if (j >= group[i - 1])
                {
                    /*
                        max(0, k - profit[i - 1])可以理解为 if(k <= profit[i - 1]) dp[i][j][k]=dp[i-1][j][k]+dp[i-1][j-group[i-1]][0];
                        如果profit[i - 1]自己就完成了盈利要求，那么前i-1个任务盈利为0即可。
                    */
                    res[i][j][k] = (res[i - 1][j][k] + res[i - 1][j - group[i - 1]][max(0, k - profit[i - 1])]) % MOD;
                }
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < n + 1; i++)
    {
        sum = (sum + res[len][i][minProfit]) % MOD;
    }

    return sum;
}

int main()
{
    // 测试用例
    // int n = 5;
    // int minProfit = 3;
    // vector<int> group = {2, 2};
    // vector<int> profit = {2, 3};

    int n, minProfit, numofgroup, idx = 0;
    cin >> n >> minProfit >> numofgroup;
    vector<int> group(numofgroup);
    vector<int> profit(numofgroup);
    while (cin >> group[idx++] && idx < numofgroup)
        ;
    idx = 0;
    while (cin >> profit[idx++] && idx < numofgroup)
        ;

    int ans = profitableSchemes(n, minProfit, group, profit);
    cout << ans << endl;

    return 0;
}
