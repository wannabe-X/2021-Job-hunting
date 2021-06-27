/*
 * @Description: 909. 蛇梯棋
 * @Author: Mr. Lee
 * @Date: 2021-06-27 12:08:33
 * @LastEditTime: 2021-06-27 13:30:57
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

pair<int, int> id2rc(int id, int n)
{
    int r = (id - 1) / n, c = (id - 1) % n;
    if (r % 2 == 1)
    {
        c = n - 1 - c;
    }
    return {n - 1 - r, c};
}

int snakesAndLadders(vector<vector<int>> &board)
{
    int n = board.size();
    queue<pair<int, int>> q;
    vector<int> vis(n * n + 1);
    q.emplace(1, 0);
    
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        for (int i = 1; i <= 6; ++i)
        {
            int nxt = p.first + i;
            if (nxt > n * n)
            { // 超出边界
                break;
            }
            auto rc = id2rc(nxt, n); // 得到下一步的行列
            if (board[rc.first][rc.second] > 0)
            { // 存在蛇或梯子
                nxt = board[rc.first][rc.second];
            }
            if (nxt == n * n)
            { // 到达终点
                return p.second + 1;
            }
            if (!vis[nxt])
            {
                vis[nxt] = true;
                q.emplace(nxt, p.second + 1); // 扩展新状态
            }
        }
    }
    return -1;
}

int main()
{
    vector<vector<int>> board = {
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 35, -1, -1, 13, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 15, -1, -1, -1, -1}};
    int ans = snakesAndLadders(board);
    cout << ans << endl;

    return 0;
}