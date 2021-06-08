#include <iostream>
#include <vector>

using namespace std;

int lastStoneWeightII(vector<int> &stones)
{
    int n = stones.size(), sum = 0, neg;
    for (int i = 0; i < n; sum += stones[i], i++)
        ;
    neg = sum / 2;
    /*
        定义二维布尔数组 dp，其中 dp[i+1][j] 表示前 i 个石头能否凑出重量 j。
        特别地，dp[0][] 为不选任何石头的状态，因此除了 dp[0][0] 为真，其余 dp[0][j] 全为假。

        若 j<stones[i]，则不能选第 i 个石头，此时有 dp[i+1][j]=dp[i][j]；
        若 j≥stones[i]，存在选或不选两种决策，不选时有 dp[i+1][j]=dp[i][j]，
            选时需要考虑能否凑出重量 stones[i]j−stones[i]，即 dp[i+1][j]=dp[i+1][j]=dp[i][j−stones[i]]。
            若二者均为假则 dp[i+1][j] 为假，否则 dp[i+1][j] 为真。

        求出 dp[n][] 后，所有为真的 dp[n][j] 中，最大的 j 即为 neg 能取到的最大值。
        代入 sum−2⋅neg 中即得到最后一块石头的最小重量。

    */
    vector<vector<int>> res(n + 1, vector<int>(neg + 1, 0));
    res[0][0] = 1;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < neg + 1; j++)
        {
            res[i][j] = res[i - 1][j];
            if (j >= stones[i - 1])
                res[i][j] = res[i][j] || res[i - 1][j - stones[i - 1]];
        }
    }

    for (int i = neg; i > -1; i--)
    {
        if (res[n][i])
            return sum - 2 * i;
    }

    return 0;
}

int main()
{
    // 测试用例
    // vector<int> stones = {1, 2};
    // int ans = lastStoneWeightII(stones);

    int n, idx = 0;
    cin >> n;
    vector<int> stones(n);
    while (cin >> stones[idx++] && idx < n)
        ;
    int ans = lastStoneWeightII(stones);
    cout << ans << endl;

    return 0;
}