/*
 * @Description: 310. 最小高度树
 * @Author: Mr. Lee
 * @Date: 2021-07-08 14:28:44
 * @LastEditTime: 2021-07-08 15:23:48
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
{

    if (n == 1)
        return {0};
    else if (n == 2)
        return {0, 1};

    // 建立入度数组
    vector<int> indegree(n, 0);
    // 装入度为1的节点
    queue<int> q;
    // 建立双向图
    vector<vector<int>> graph(n);
    for (auto &edge : edges)
    {
        indegree[edge[0]]++;
        indegree[edge[1]]++;
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 1)
            q.push(i);
    }

    int cnt = q.size();

    while (n > 2)
    {
        n -= cnt;
        while (cnt--)
        {
            int tmp = q.front();
            q.pop();
            indegree[tmp] = 0;

            for (int i = 0; i < graph[tmp].size(); i++)
            {
                if (indegree[graph[tmp][i]] != 0)
                {
                    indegree[graph[tmp][i]]--;
                    if (indegree[graph[tmp][i]] == 1)
                    {
                        q.push(graph[tmp][i]);
                    }
                }
            }
        }
        cnt = q.size();
    }

    vector<int> res;
    while (!q.empty())
    {
        res.push_back(q.front());
        q.pop();
    }

    return res;
}

int main()
{
    int n = 8;
    // vector<vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}};
    vector<vector<int>> edges = {{0,1},{1,2},{2,3},{0,4},{4,5},{4,6},{6,7}};
    vector<int> ans = findMinHeightTrees(n, edges);
    for (int root : ans)
    {
        cout << root << " ";
    }
    cout << endl;

    return 0;
}
