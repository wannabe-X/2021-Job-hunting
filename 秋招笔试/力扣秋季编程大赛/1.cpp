/*
 * @Description: 2. 自行车炫技赛场
 * @Author: Mr. Lee
 * @Date: 2021-09-25 14:59:53
 * @LastEditTime: 2021-09-25 17:51:10
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
vector<vector<int>> res;
set<pair<int, int>> st;

static bool comp(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
        return a[1] < b[1];

    return a[0] < b[0];
}

void dfs(vector<int> &position, vector<vector<int>> &terrain, vector<vector<int>> &obstacle, vector<vector<bool>> &visited, int x, int y, int speed)
{
    if (visited[x][y] || speed <= 0)
        return;

    if (speed == 1 && (x != position[0] || y != position[1]))
    {
        st.insert(make_pair(x, y));
    }

    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int a = x + dx[i], b = y + dy[i];
        if (a >= 0 && a < terrain.size() && b >= 0 && b < terrain[0].size() && !visited[a][b])
        {
            dfs(position, terrain, obstacle, visited, a, b, speed + (terrain[x][y] - terrain[a][b] - obstacle[a][b]));
        }
    }
    visited[x][y] = false;
}

vector<vector<int>> bicycleYard(vector<int> &position, vector<vector<int>> &terrain, vector<vector<int>> &obstacle)
{
    vector<vector<bool>> visited(terrain.size(), vector<bool>(terrain.size(), false));
    dfs(position, terrain, obstacle, visited, position[0], position[1], 1);
    for (auto it = st.begin(); it != st.end(); it++)
    {
        res.push_back({(*it).first, (*it).second});
    }
    sort(res.begin(), res.end(), comp);
    return res;
}

int main(void)
{
    vector<int> position = {0, 0};
    vector<vector<int>> terrain = {{0, 0}, {0, 0}}, obstacle = {{0, 0}, {0, 0}};
    vector<vector<int>> ans = bicycleYard(position, terrain, obstacle);
    for (auto &x : ans)
    {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}