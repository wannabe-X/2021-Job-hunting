/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-08-25 18:47:44
 * @LastEditTime: 2021-08-25 20:15:00
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int func(vector<vector<int>> &v)
{
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i][0] == -1)
        {
            sum += v[i][1];
        }
    }

    return sum;
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> v[i][j];
        }
    }

    int ans = func(v);
    cout << ans;

    return 0;
}