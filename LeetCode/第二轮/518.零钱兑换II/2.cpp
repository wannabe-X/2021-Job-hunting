/*
 * @Description: LeetCode 518. 零钱兑换 II。动态规划，优化成一维数组
 * @Author: Mr. Lee
 * @Date: 2021-06-10 10:25:54
 * @LastEditTime: 2021-06-10 10:54:05
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int change(int amount, vector<int> &coins)
{
    vector<int> res(amount + 1);
    res[0] = 1;

    for (int i = 0; i < coins.size(); i++)
    {
        for (int j = coins[i]; j <= amount; j++)
        {
            res[j] += res[j - coins[i]];
        }
    }

    return res[amount];
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

