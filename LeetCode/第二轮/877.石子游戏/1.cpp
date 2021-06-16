/*
 * @Description: 877. 石子游戏
 * @Author: Mr. Lee
 * @Date: 2021-06-16 15:16:00
 * @LastEditTime: 2021-06-16 17:37:28
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

/*
    定义二维数组 dp，其行数和列数都等于石子的堆数，dp[i][j] 表示当剩下的石子堆为下标 i 到下标 j 时，
    当前玩家与另一个玩家的石子数量之差的最大值，注意当前玩家不一定是先手 Alex。
*/

/*
    dp[i][j]表示从第i到j堆石头，Alex（先手）能领先Lee（后手）的最大分值。
        1.Alex拿走第j堆，则相当于变成：Alex初始分数为piles[j]，第i到j-1堆，且Lee先手。
            dp[i][j] = piles[j] + (-dp[i][j-1])
        2.Alex拿走第i堆，则相当于变成：Alex初始分数为piles[i]，第i+1到j堆，且Lee先手。
            dp[i][j] = piles[i] + (-dp[i+1][j])
    二者取大。
*/
bool stoneGame(vector<int> &piles)
{
    int length = piles.size();
    vector<vector<int>> dp(length, vector<int>(length, 0));

    for (int i = 0; i < length; i++)
    {
        dp[i][i] = piles[i];
    }

    for (int i = length - 2; i > -1; i--)
    {
        for (int j = i + 1; j < length; j++)
        {
            /*
                dp[i][j]是当前玩家的得分
                piles[i]指的是当前玩家从左边拿走石子的得分，dp[i + 1][j]指的是另外一个玩家的净得分，二者之差即为当前玩家的净得分
                dp[i + 1][j]可以理解为Lee领先Alex的分数，所以需要用减号
            */
            int left = piles[i] - dp[i + 1][j];  // 取走的是左边的石子
            int right = piles[j] - dp[i][j - 1]; // 取走的是右边的石子
            dp[i][j] = max(left, right);         // 两种策略取最大值
        }
    }

    return dp[0][length - 1] > 0;
}

int main()
{
    // 测试用例
    // vector<int> piles = {5, 3, 4, 5};
    // bool ans = stoneGame(piles);

    int numofpile, idx = 0;
    cin >> numofpile;
    vector<int> piles(numofpile);
    while (cin >> piles[idx++] && idx < numofpile)
        ;
    bool ans = stoneGame(piles);
    cout << boolalpha << ans << endl;

    return 0;
}
