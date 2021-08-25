/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-08-23 14:50:27
 * @LastEditTime: 2021-08-23 20:05:50
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMinLength(vector<vector<int>> &pearls)
{
    int res = INT_MAX;
    vector<int> dis;
    for (int i = 0; i < pearls.size(); i++)
    {
        dis.clear();
        for (int j = 0; j < pearls.size(); j++)
        {
            if (i != j)
            {
                int distance = abs(pearls[i][0] - pearls[j][0]) + abs(pearls[i][1] - pearls[j][1]);
                dis.push_back(distance);
            }
        }
        sort(dis.begin(), dis.end());
        res = min(res, dis[0] + dis[1]);
    }

    return res;
}

int main()
{
    vector<vector<int>> nums = {{0, 0},
                                {0, 2},
                                {1, 1},
                                {10, 10}};
    int ans = getMinLength(nums);
    cout << ans << endl;

    return 0;
}