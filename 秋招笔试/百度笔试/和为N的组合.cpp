/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-08-27 17:38:28
 * @LastEditTime: 2021-08-27 17:42:47
 * @LastEditors: Mr. Lee
 */

// C++找出数组中和为N的所有配对(不可重复)
#include <iostream>
#include <vector>
using namespace std;

void SumK(vector<vector<int>> &res, vector<int> &a, int sum, vector<int> &v, int cur)
{
    if (sum == 0)
    {
        res.push_back(v);
        return;
    }

    for (int i = cur; i < a.size(); i++)
    {
        if (a[i] <= sum)
        {
            v.push_back(a[i]);
            SumK(res, a, sum - a[i], v, i + 1);
            v.pop_back();
        }
    }
}

int main()
{
    cout << "begin" << endl;
    vector<int> a;
    for (int i = 6; i >= 0; i--)
    {
        a.push_back(i);
    }
    vector<int> v;
    vector<vector<int>> res;
    SumK(res, a, 6, v, 0);
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << "【 ";
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << "】" << endl;
    }
}
