/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-24 18:57:15
 * @LastEditTime: 2021-09-24 19:56:03
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int res = INT_MAX;
int tmp = 0;

void dfs(vector<int> &w, vector<int> &p, vector<vector<int>> &graph, int cur, int end, vector<int> seen)
{
    if (cur == end)
    {
        res = min(res, tmp);
        return;
    }

    for (auto &x : graph[cur])
    {
        tmp += p[cur];
    }
}

int func(vector<int> &w, vector<int> &p, vector<vector<int>> &u_v_c, int s, int t)
{
    int res = -1;
    int n = w.size();
    int m = u_v_c.size();
    vector<bool> seen(n, false);
    vector<vector<int>> graph(m);
    for (int i = 0; i < m; i++)
    {
        graph[u_v_c[i][0]].push_back(u_v_c[i][1]);
    }
    int src = -1;
    for (int i = 0; i < graph.size(); i++)
    {
        if (u_v_c[i][0] == s)
        {
            src = i;
            break;
        }
    }

    return res == INT_MAX ? -1 : res;
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<int> w(n, 0);
    for (int i = 0; i < n; i++)
        cin >> w[i];
    vector<int> p(n, 0);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    vector<vector<int>> u_v_c(m, vector<int>(3, 0));
    for (int i = 0; i < m; i++)
    {
        cin >> u_v_c[i][0] >> u_v_c[i][1] >> u_v_c[i][2];
    }
    int s, t;
    cin >> s >> t;
    int ans = func(w, p, u_v_c, s, t);
    cout << ans;

    return 0;
}