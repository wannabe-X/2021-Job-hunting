/*
 * @Description:LeetCode 879. 盈利计划。优化为二维数组
 * @Author: Mr. Lee
 * @Date: 2021-06-09 16:11:53
 * @LastEditTime: 2021-06-09 16:25:14
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
{
    int len = group.size(), MOD = (int)1e9 + 7;
    vector<vector<int>> res(n + 1, vector<int>(minProfit + 1, 0));
    for (int i = 0; i < n + 1; i++)
        res[i][0] = 1;

    for (int i = 1; i < len + 1; i++)
    {
        for (int j = n; j >= group[i - 1]; j--)
        {
            for (int k = minProfit; k >= 0; k--)
            {

                res[j][k] = (res[j][k] + res[j - group[i - 1]][max(0, k - profit[i - 1])]) % MOD;
            }
        }
    }

    return res[n][minProfit];
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
