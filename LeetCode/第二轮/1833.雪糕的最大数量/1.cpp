/*
 * @Description: 1833. 雪糕的最大数量
 * @Author: Mr. Lee
 * @Date: 2021-07-02 00:19:36
 * @LastEditTime: 2021-07-02 00:40:52
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxIceCream(vector<int> &costs, int coins)
{
    sort(costs.begin(), costs.end());
    int count = 0;
    for (int num : costs)
    {
        if (coins >= num)
        {
            coins -= num;
            count++;
        }
    }

    return count;
}

int main()
{
    vector<int> costs = {1, 3, 2, 4, 1};
    int coins = 7;
    int ans = maxIceCream(costs, coins);
    cout << ans << endl;

    return 0;
}