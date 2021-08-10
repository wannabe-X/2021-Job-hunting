/*
 * @Description: 802. 找到最终的安全状态
 * @Author: Mr. Lee
 * @Date: 2021-08-05 18:10:24
 * @LastEditTime: 2021-08-09 16:29:24
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include<queue>

using namespace std;

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<vector<int>> rg(n);
    vector<int> inDeg(n);
    
    for (int x = 0; x < n; ++x)
    {
        for (int y : graph[x])
        {
            rg[y].push_back(x);
        }
        inDeg[x] = graph[x].size();
    }

    queue<int> q;
    for (int i = 0; i < n; ++i)
    {
        if (inDeg[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int y = q.front();
        q.pop();
        for (int x : rg[y])
        {
            if (--inDeg[x] == 0)
            {
                q.push(x);
            }
        }
    }

    vector<int> ans;
    for (int i = 0; i < n; ++i)
    {
        if (inDeg[i] == 0)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    vector<int> ans = eventualSafeNodes(graph);
    for (auto &x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
