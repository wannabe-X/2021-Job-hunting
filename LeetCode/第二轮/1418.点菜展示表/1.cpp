/*
 * @Description: 1418. 点菜展示表
 * @Author: Mr. Lee
 * @Date: 2021-07-06 00:02:35
 * @LastEditTime: 2021-07-06 01:03:19
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<vector<string>> displayTable(vector<vector<string>> &orders)
{
    vector<vector<string>> res;
    vector<string> tmp;
    map<int, vector<string>> m;
    set<string> s;
    map<string, int> m1;

    for (int i = 0; i < orders.size(); i++)
    {
        m[stoi(orders[i][1])].push_back(orders[i][2]);
        s.insert(orders[i][2]);
    }

    // 制作表头
    int idx = 0;
    tmp.push_back("Table");
    for (auto it = s.begin(); it != s.end(); it++)
    {
        tmp.push_back((*it));
        m1[(*it)] = idx++;
    }
    res.push_back(tmp);
    tmp.clear();

    // 制作表体
    for (auto it = m.begin(); it != m.end(); it++)
    {
        tmp.push_back(to_string((*it).first));
        vector<int> v(res[0].size() - 1, 0);
        for (int i = 0; i < (*it).second.size(); i++)
        {
            v[m1[(*it).second[i]]]++;
        }

        for (int i = 0; i < v.size(); i++)
        {
            tmp.push_back(to_string(v[i]));
        }
        res.push_back(tmp);
        tmp.clear();
    }

    return res;
}

int main()
{
    vector<vector<string>> orders = {{"David", "3", "Ceviche"}, {"Corina", "10", "Beef Burrito"}, {"David", "3", "Fried Chicken"}, {"Carla", "5", "Water"}, {"Carla", "5", "Ceviche"}, {"Rous", "3", "Ceviche"}};
    vector<vector<string>> ans = displayTable(orders);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
