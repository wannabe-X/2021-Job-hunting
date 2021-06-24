/*
 * @Description: 149. 直线上最多的点数
 * @Author: Mr. Lee
 * @Date: 2021-06-24 09:27:11
 * @LastEditTime: 2021-06-24 10:58:03
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

/*
    常规思路：
        以每一个点为基础，计算其余所有点与该点的斜率大小，如果斜率大小相同，则证明在同一条直线上。同时使用map来记录点的个数
        每经过一轮，计算map中最大的值，用来更新结果
        最后，对结果加1
*/
int maxPoints(vector<vector<int>> &points)
{
    int n = points.size();
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        map<double, int> slope;

        for (int j = 0; j < n; j++)
        {
            if (i != j && points[i][0] - points[j][0] == 0)
            {
                slope[__DBL_MAX__]++;
            }
            else if (i != j)
            {
                double k = (points[i][1] - points[j][1] + 0.0) / (points[i][0] - points[j][0]);
                slope[k]++;
            }
        }

        if (slope.size() > 0)
        {
            auto max_k = *max_element(slope.begin(), slope.end(), [](const pair<double, int> left, const pair<double, int> right)
                                      { return left.second < right.second; });
            res = max(res, max_k.second);
        }

        if (res + 1 > points.size() / 2)
            break;
    }

    res += 1;

    return res;
}

int main()
{
    // 测试用例
    // vector<vector<int>> points = {{1, 1}, {3, 2}, {5, 3},{4,1},{2,3},{1,4}};
    // vector<vector<int>> points = {{1, 1}, {2, 2}, {3, 3}};
    // vector<vector<int>> points = {{0, 0}};
    // vector<vector<int>> points = {{0, 1}, {0, 0}};

    int numofpoint, idx = 0;
    cin >> numofpoint;
    vector<vector<int>> points(numofpoint, vector<int>(2, 0));
    while (idx++ < numofpoint && cin >> points[idx][0] >> points[idx][1])
        ;
    int ans = maxPoints(points);
    cout << ans << endl;

    return 0;
}
