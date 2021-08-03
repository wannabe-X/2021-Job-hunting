/*
 * @Description: 743. 网络延迟时间
 * @Author: Mr. Lee
 * @Date: 2021-08-02 18:31:46
 * @LastEditTime: 2021-08-02 19:11:58
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int ans = -1, tmp = 0;

void boardtrack(vector<vector<int>> &times, unordered_map<int, vector<pair<int, int>>> &m,
                vector<bool> &board, int k)
{
    if (m[k].size() == 0)
        return;

    for (int i = 0; i < m[k].size() && board[k]; i++)
    {
        tmp += m[k][i].second;
        board[k] = 0;
        boardtrack(times, m, board, m[k][i].first);
        ans = max(ans, tmp);
        tmp -= m[k][i].second;
    }
}

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    unordered_map<int, vector<pair<int, int>>> m;

    // 建立有向图
    for (auto &x : times)
    {
        m[x[0]].push_back(make_pair(x[1], x[2]));
    }

    vector<bool> board(n + 1, 1);

    boardtrack(times, m, board, k);

    return ans;
}

int main()
{
    vector<vector<int>> times = {{1, 2, 1}, {2, 1, 3}};
    int n = 2, k = 2;

    int ans = networkDelayTime(times, n, k);
    cout << ans << endl;

    return 0;
}
