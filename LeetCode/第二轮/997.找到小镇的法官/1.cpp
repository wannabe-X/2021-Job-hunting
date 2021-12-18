/*
 * @Description: 997. 找到小镇的法官
 * @Author: Mr. Lee
 * @Date: 2021-12-19 00:16:19
 * @LastEditTime: 2021-12-19 00:23:43
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findJudge(int n, vector<vector<int>> &trust)
{
    vector<int> in(n + 1), out(n + 1);
    for (vector<int> edge : trust)
    {
        in[edge[1]]++;
        out[edge[0]]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (in[i] == n - 1 && out[i] == 0)
            return i;
    }

    return -1;
}

int main(int argc, char *argv[])
{
    int n = 3;
    vector<vector<int>> trust = {{1, 3}, {2, 3}};
    int ans = findJudge(n, trust);
    cout << ans << endl;

    return 0;
}