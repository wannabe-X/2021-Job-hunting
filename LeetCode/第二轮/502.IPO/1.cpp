/*
 * @Description: 502. IPO
 * @Author: Mr. Lee
 * @Date: 2021-09-08 00:17:12
 * @LastEditTime: 2021-09-08 00:44:09
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>

using namespace std;

// 贪心算法,每次都选择能做的 赚取利润最大的项目
int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
{
    int res = 0;
    vector<int> idxC(profits.size());
    std::iota(begin(idxC), end(idxC), 0);
    sort(idxC.begin(), idxC.end(), [&](int a, int b)
         { return capital[a] < capital[b]; });

    priority_queue<int> pq;
    auto left = begin(idxC);

    while (k--)
    {
        while (left < end(idxC) && capital[*left] <= w)
            pq.push(profits[*left++]);

        if (pq.empty())
            return w;
        w += pq.top();
        pq.pop();
    }

    return w;
}

int main(void)
{
    int k, w;
    vector<int> profits = {1, 2, 3}, capital = {0, 1, 1};
    int ans = findMaximizedCapital(k, w, profits, capital);
    cout << ans << endl;

    return 0;
}