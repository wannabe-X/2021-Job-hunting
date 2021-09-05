/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-04 09:57:22
 * @LastEditTime: 2021-09-04 11:55:59
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int func(vector<vector<int>> &v, int n, int k)
{
    const int inf = INT_MAX / 2;
    vector<vector<int>> g(n, vector<int>(n, inf));
    for (auto &t : v)
    {
        int x = t[0] - 1, y = t[1] - 1;
        g[x][y] = t[2];
    }

    vector<int> dist(n, inf);

    dist[k - 1] = 0;
    vector<bool> used(n);

    for (int i = 0; i < n; i++)
    {
        int x = -1;
        for (int y = 0; y < n; y++)
        {
            if (!used[y] && (x == -1 || dist[y] < dist[x]))
                x = y;
        }

        used[x] = true;

        for (int y = 0; y < n; y++)
        {
            dist[y] = min(dist[y], dist[x] + g[x][y]);
        }

        int ans = *max_element(dist.begin(), dist.end());

        return ans == inf ? -1 : ans;
    }

    return 0;
}

int main(void)
{
    int N, K;
    cin >> N >> K;
    vector<vector<int>> v(N - 1, vector<int>(3, 0));
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> v[i][j];
        }
    }

    int ans = func(v, N, K);
    cout << ans;
    return 0;
}
