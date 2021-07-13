/*
 * @Description: 218. 天际线问题
 * @Author: Mr. Lee
 * @Date: 2021-07-13 00:18:14
 * @LastEditTime: 2021-07-13 00:44:02
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include<set>

using namespace std;

vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
{
    multiset<pair<int, int>> all;
    vector<vector<int>> res;

    for (auto &e : buildings)
    {
        all.insert(make_pair(e[0], -e[2])); // critical point, left corner
        all.insert(make_pair(e[1], e[2]));  // critical point, right corner
    }

    multiset<int> heights({0}); // 保存当前位置所有高度。
    vector<int> last = {0, 0};  // 保存上一个位置的横坐标以及高度
    for (auto &p : all)
    {
        if (p.second < 0)
            heights.insert(-p.second); // 左端点，高度入堆
        else
            heights.erase(heights.find(p.second)); // 右端点，移除高度

        // 当前关键点，最大高度
        auto maxHeight = *heights.rbegin();

        // 当前最大高度如果不同于上一个高度，说明这是一个转折点
        if (last[1] != maxHeight)
        {
            // 更新 last，并加入结果集
            last[0] = p.first;
            last[1] = maxHeight;
            res.push_back(last);
        }
    }

    return res;
}

int main(int argc, char *argv[])
{
    vector<vector<int>> buildings = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    vector<vector<int>> skylines = getSkyline(buildings);
    for (auto &skyline : skylines)
    {
        for (auto &point : skyline)
        {
            cout << point << " ";
        }
    }
    return 0;
}
