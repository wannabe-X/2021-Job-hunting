/*
 * @Description: 剑指 Offer II 082. 含有重复元素集合的组合
 * @Author: Mr. Lee
 * @Date: 2021-09-07 09:30:14
 * @LastEditTime: 2021-09-07 09:41:02
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> res;
vector<int> tmp;
int sum = 0;

bool checkRepeat(vector<vector<int>> &res, vector<int> &t)
{
    for (auto &x : res)
    {
        if (x == t)
            return false;
    }
    return true;
}

void boardtrack(vector<int> &candidates, int target, int idx)
{
    if (sum >= target)
    {
        if (sum == target && checkRepeat(res, tmp))
            res.push_back(tmp);
        return;
    }

    for (int i = idx; i < candidates.size(); i++)
    {
        tmp.push_back(candidates[i]);
        sum += candidates[i];
        boardtrack(candidates, target, i + 1);
        tmp.pop_back();
        sum -= candidates[i];
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    boardtrack(candidates, target, 0);
    return res;
}

int main(void)
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> ans = combinationSum2(candidates, target);
    for (auto &x : ans)
    {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }

    return 0;
}