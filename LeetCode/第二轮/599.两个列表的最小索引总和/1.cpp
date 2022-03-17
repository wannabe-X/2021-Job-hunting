/*
 * @Description: 599. 两个列表的最小索引总和
 * @Author: Mr. Lee
 * @Date: 2022-03-14 23:10:01
 * @LastEditTime: 2022-03-14 23:30:09
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
{
    vector<string> res;
    unordered_map<string, int> m;
    int minIdx = INT8_MAX;
    for (int i = 0; i < list1.size(); i++)
        m[list1[i]] = i;
    for (int i = 0; i < list2.size(); i++)
    {
        if (m.count(list2[i]))
        {
            int tmpInx = i + m[list2[i]];
            if (tmpInx <= minIdx)
            {
                if (tmpInx < minIdx)
                    res.clear();
                res.push_back(list2[i]);
                minIdx = tmpInx;
            }
        }
    }

    return res;
}

int main(int argc, char *argv[])
{
    vector<string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"}, list2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
    vector<string> ans = findRestaurant(list1, list2);
    for (string str : ans)
        cout << str << " ";

    return 0;
}