/*
 * @Description: 剑指 Offer II 081. 允许重复选择元素的组合
 * @Author: Mr. Lee
 * @Date: 2021-09-06 17:39:15
 * @LastEditTime: 2021-09-06 22:28:36
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> res;
vector<int> tmp;
int sum = 0;

bool checkRepeat(vector<vector<int>> &res, vector<int> target)
{
    for (auto &x : res)
        if (target == x)
            return false;

    return true;
}

void boardtrack(vector<int> &candidates, int target)
{
    if (sum >= target)
    {
        vector<int> t = tmp;
        sort(t.begin(), t.end());

        if (sum == target && checkRepeat(res, t))
        {
            res.push_back(t);
        }

        return;
    }

    for (int i = 0; i < candidates.size(); i++)
    {
        tmp.push_back(candidates[i]);
        sum += candidates[i];
        boardtrack(candidates, target);
        tmp.pop_back();
        sum -= candidates[i];
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    boardtrack(candidates, target);
    return res;
}

int main(void)
{
    vector<int> candidates = {3, 5, 8};
    int target = 11;
    vector<vector<int>> ans = combinationSum(candidates, target);
    for (auto &x : ans)
    {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }

    return 0;
}