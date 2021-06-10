/*
 * @Description: LeetCode 518. 零钱兑换 II。动态规划，二维数组
 * @Author: Mr. Lee
 * @Date: 2021-06-10 09:28:30
 * @LastEditTime: 2021-06-10 10:53:46
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    // res[i][j] 表示使用前i个硬币，凑成金额j的方案数
    vector<vector<int>> res(n + 1, vector<int>(amount + 1, 0));
    // 初始化 无论多少个硬币面值，都可以凑出来0元
    for (int i = 0; i < n + 1; res[i][0] = 1, i++)
        ;
    
    /*
        正确的子问题定义应该是，problem(k,i) = problem(k-1, i) + problem(k, i-coins[k])

        即前k个硬币凑齐金额i的组合数等于前k-1个硬币凑齐金额i的组合数加上在原来i-k的基础上使用硬币的组合数。
        说的更加直白一点，那就是用前k的硬币凑齐金额i，要分为两种情况计算，
        一种是没有用第K个硬币就凑齐了，一种是前面已经凑到了i-coins[k]，现在就差第k个硬币了。
    */
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < amount + 1; j++)
        {
            // 如果j小于当前的硬币面值，那么就应该不将该金额包含在方案中
            res[i][j] = res[i - 1][j];
            if (j >= coins[i - 1])
                // 如果j大于等于当前的硬币面值，那么就应该将该金额包含在方案中
                res[i][j] += res[i][j - coins[i - 1]];
        }
    }

    return res[n][amount];
}

int main()
{
    // 测试用例
    // int amount = 5;
    // vector<int> coins = {1, 2, 5};

    int amount, numofamount;
    int idx = 0;
    cin >> amount >> numofamount;
    vector<int> coins(numofamount, 0);
    while (cin >> coins[idx++] && idx < numofamount)
        ;

    int ans = change(amount, coins);
    cout << ans << endl;

    return 0;
}