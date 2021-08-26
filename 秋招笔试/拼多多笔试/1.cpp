/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-07-25 18:51:59
 * @LastEditTime: 2021-07-26 16:43:43
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool func(vector<vector<int>> &m)
{
    sort(m.begin(), m.end(),
         [](const vector<int> &a, const vector<int> &b)
         { return a[1] < b[1] || a[0] < b[0]; });
    for (int i = 0; i < m.size() - 1; i++)
    {
        if (m[i][1] <= m[i + 1][0])
        {
            continue;
        }
        if (m[i][0] >= m[i + 1][0])
            return true;
    }

    return false;
}

int main()
{
    int n;
    vector<vector<int>> m(n, vector<int>(2, 0));
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m[i][0] >> m[i][1];
    }

    bool ans = func(m);
    cout << ans << endl;

    return 0;
}
