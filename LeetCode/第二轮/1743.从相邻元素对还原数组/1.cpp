/*
 * @Description: 1743. 从相邻元素对还原数组
 * @Author: Mr. Lee
 * @Date: 2021-07-25 00:02:54
 * @LastEditTime: 2021-07-25 00:48:34
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
{
    vector<int> res;

    // 构建无向图
    unordered_map<int, vector<int>> m;
    for (auto &adj : adjacentPairs)
    {
        m[adj[0]].push_back(adj[1]);
        m[adj[1]].push_back(adj[0]);
    }
    
    // 只出现过一次的元素必定是图的起点或终点
    for (auto it = m.begin(); it != m.end(); it++)
    {
        if ((*it).second.size() == 1)
        {
            res.push_back((*it).first);
            res.push_back((*it).second[0]);
            break;
        }
    }

    // 按照相邻关系还原数组
    for (int i = 2; i < adjacentPairs.size() + 1; i++)
    {
        auto &adj = m[res[i - 1]];
        res.push_back(res[i - 2] == adj[0] ? adj[1] : adj[0]);
    }

    return res;
}

int main()
{
    vector<vector<int>> adjacentPairs = {{2, 1}, {3, 4}, {3, 2}};
    vector<int> ans = restoreArray(adjacentPairs);
    for (auto &num : ans)
        cout << num << " ";
    cout << endl;

    return 0;
}
