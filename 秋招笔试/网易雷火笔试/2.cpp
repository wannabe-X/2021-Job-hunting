/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-18 13:57:59
 * @LastEditTime: 2021-09-18 16:06:10
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}

vector<int> func(vector<vector<int>> &nums, int R)
{
    vector<vector<int>> res;
    int x = 10001, y = 10001;
    int x1 = 0, y1 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        
    }

    return res[0];
}

int main(void)
{
    int R, N;
    cin >> R;
    cin >> N;
    vector<vector<int>> v(N, vector<int>(2, 0));
    for (int i = 0; i < N; i++)
    {
        cin >> v[i][0] >> v[i][1];
    }
    vector<int> ans = func(v, R);
    cout << ans[0] << " " << ans[1];

    return 0;
}