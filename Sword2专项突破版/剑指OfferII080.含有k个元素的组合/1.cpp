/*
 * @Description: 剑指 Offer II 080. 含有 k 个元素的组合
 * @Author: Mr. Lee
 * @Date: 2021-09-06 14:32:15
 * @LastEditTime: 2021-09-06 14:47:02
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> res;
vector<int> tmp;

void boardtrack(int n, int idx, int k)
{
    if (tmp.size() == k)
    {
        res.push_back(tmp);
        return;
    }

    for (int i = idx; i <= n; i++)
    {
        tmp.push_back(i);
        boardtrack(n, i + 1, k);
        tmp.pop_back();
    }
}

vector<vector<int>> combine(int n, int k)
{
    boardtrack(n, 1, k);
    return res;
}

int main(void)
{
    int n = 4, k = 2;
    vector<vector<int>> ans = combine(n, k);
    for (auto &x : ans)
    {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }

    return 0;
}