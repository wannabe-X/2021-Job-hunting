/*
 * @Description: 815. 公交路线。BFS提交超时
 * @Author: Mr. Lee
 * @Date: 2021-06-28 09:18:24
 * @LastEditTime: 2021-06-28 10:32:54
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> getNextStatus(vector<vector<int>> &routes, int status)
{
    vector<int> bus, transtatus;
    for (int i = 0; i < routes.size(); i++)
    {
        if (find(routes[i].begin(), routes[i].end(), status) != routes[i].end())
        {
            for (int j = 0; j < routes[i].size(); j++)
            {
                if (routes[i][j] != status)
                    transtatus.push_back(routes[i][j]);
            }
        }
    }

    return transtatus;
}

int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
{

    if (source == target)
    {
        return 0;
    }

    queue<pair<int, int>> q;
    unordered_set<int> seen = {source};
    q.emplace(source, 0);

    while (!q.empty())
    {
        int status = q.front().first;
        int step = q.front().second;
        q.pop();

        // vector<int> nextstatus = getNextStatus(routes, status);

        for (int &nxtStatus : getNextStatus(routes, status))
        {
            if (!seen.count(nxtStatus))
            {
                if (nxtStatus == target)
                {
                    return step + 1;
                }
                q.emplace(nxtStatus, step + 1);
                seen.insert(move(nxtStatus));
            }
        }
    }

    return -1;
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
