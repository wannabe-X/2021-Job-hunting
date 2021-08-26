/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-08-25 18:47:36
 * @LastEditTime: 2021-08-25 19:48:13
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int maxSubMat(vector<vector<int>> &v)
{
    int maxSum = v[0][0];
    int sum[v.size()], dp[v.size()];
    for (int i = 0; i < v[0].size(); i++)
    {
        memset(sum, 0, sizeof(sum));
        for (int j = i; j < v.size(); j++)
        {
            for (int k = 0; k < v.size(); k++)
            {
                sum[k] += v[k][j];
            }

            dp[0] = sum[0];

            maxSum = max(dp[0], maxSum);

            for (int k = 1; k < v.size(); k++)
            {
                dp[k] = max(sum[k], dp[k - 1] + sum[k]);
                maxSum = max(dp[k], maxSum);
            }
        }
    }

    return maxSum;
}


int main(int argc, char *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    int ans = maxSubMat(v);
    cout << ans;

    return 0;
}