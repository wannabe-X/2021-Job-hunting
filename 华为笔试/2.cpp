/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-08-25 18:47:41
 * @LastEditTime: 2021-08-25 21:34:55
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int minTime = INT_MAX;
int row, col;
bool flag = false;

void dfs(vector<vector<int>> &v, vector<vector<bool>> &visited, int time, int i, int j)
{
    if (v[i][j] <= time)
    {
        return;
    }

    if ((i == row - 1) && (j == col - 1))
    {
        minTime = min(minTime, time);
        flag = true;
    }

    if ((i != row - 1) && (v[i + 1][j] > time + 1) && (!visited[i + 1][j]))
    {
        visited[i][j] = true;
        dfs(v, visited, time + 1, i + 1, j);
    }

    if ((j != col - 1) && (v[i][j + 1] > time + 1) && (!visited[i][j + 1]))
    {
        visited[i][j] = true;
        dfs(v, visited, time + 1, i, j + 1);
    }

    if ((i != 0) && (v[i - 1][j] > time + 1) && (!visited[i - 1][j]))
    {
        visited[i][j] = true;
        dfs(v, visited, time + 1, i - 1, j);
    }

    if ((j != 0) && (v[i][j - 1] > time + 1) && (!visited[i][j - 1]))
    {
        visited[i][j] = true;
        dfs(v, visited, time + 1, i, j - 1);
    }

    visited[i][j] = false;
}

int main(int argc, char *argv[])
{
    cin >> row >> col;
    vector<vector<int>> v(row, vector<int>(col, 0));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> v[i][j];
        }
    }

    if (v[0][0] == 0 || v[row - 1][col - 1] < row + col - 1)
    {
        cout << -1;
    }
    else
    {
        vector<vector<bool>> visited(row, vector<bool>(col, 0));
        dfs(v, visited, 0, 0, 0);
        if (flag)
        {
            cout << minTime;
        }
        else
        {
            cout << -1;
        }
    }

    return 0;
}