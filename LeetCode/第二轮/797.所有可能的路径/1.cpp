/*
 * @Description: 797. 所有可能的路径
 * @Author: Mr. Lee
 * @Date: 2021-08-25 10:49:21
 * @LastEditTime: 2021-08-25 11:26:01
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> res;
vector<int> tmp;

void boardtrack(vector<vector<int>> &graph, vector<int> &subGraph)
{
    if (tmp.back() == graph.size() - 1)
    {
        res.push_back(tmp);
        return;
    }

    if (subGraph.empty())
    {
        return;
    }

    for (int i = 0; i < subGraph.size(); i++)
    {
        tmp.push_back(subGraph[i]);
        boardtrack(graph, graph[subGraph[i]]);
        tmp.pop_back();
    }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    if (graph.empty())
        return {};
    tmp.push_back(0);
    boardtrack(graph, graph[0]);

    return res;
}

int main(int argc, char *argv[])
{
    vector<vector<int>> graph = {{1, 2}, {3}, {3}, {}};
    vector<vector<int>> ans = allPathsSourceTarget(graph);
    for (int i = 0; i < ans.size(); i++)
    {
        int j = 0;
        for (; j < ans[i].size() - 1; j++)
        {
            cout << ans[i][j] << "->";
        }
        cout << ans[i][j];
        cout << endl;
    }
    
    return 0;
}
