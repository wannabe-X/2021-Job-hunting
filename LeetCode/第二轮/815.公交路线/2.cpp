/*
 * @Description: 815. 公交路线。BFS 参考代码
 * @Author: Mr. Lee
 * @Date: 2021-06-28 09:18:24
 * @LastEditTime: 2021-06-28 10:32:34
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
{
    if (source == target)
    {
        return 0;
    }

    int n = routes.size();
    vector<vector<int>> edge(n, vector<int>(n));
    unordered_map<int, vector<int>> rec;
    for (int i = 0; i < n; i++)
    {
        for (auto &site : routes[i])
        {
            for (auto &j : rec[site])
            {
                edge[i][j] = edge[j][i] = true;
            }
            rec[site].push_back(i);
        }
    }

    vector<int> dis(n, -1);
    queue<int> que;
    for (auto &site : rec[source])
    {
        dis[site] = 1;
        que.push(site);
    }
    while (!que.empty())
    {
        int x = que.front();
        que.pop();
        for (int y = 0; y < n; y++)
        {
            if (edge[x][y] && dis[y] == -1)
            {
                dis[y] = dis[x] + 1;
                que.push(y);
            }
        }
    }

    int ret = INT_MAX;
    for (auto &site : rec[target])
    {
        if (dis[site] != -1)
        {
            ret = min(ret, dis[site]);
        }
    }
    return ret == INT_MAX ? -1 : ret;
}

int main()
{
    // 测试用例
    // vector<vector<int>> routes = {{1, 2, 7}, {3, 6, 7}};
    // int source = 1, target = 6;

    // vector<vector<int>> routes = {{7, 12}, {4, 5, 15}, {6}, {15, 19}, {9, 12, 13}};
    // int source = 15, target = 12;

    // vector<vector<int>> routes = {{1, 7}, {3, 5}};
    // int source = 5, target = 5;

    // vector<vector<int>> routes = {{2}, {2, 8}};
    // int source = 8, target = 2;

    int m, n;
    cin >> m >> n;
    vector<vector<int>> routes(m, vector<int>(n));
    int source = 1, target = 6;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> routes[i][j];
        }
    }

    int ans = numBusesToDestination(routes, source, target);
    cout << ans << endl;

    return 0;
}
