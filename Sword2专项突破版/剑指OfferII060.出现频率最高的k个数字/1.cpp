/*
 * @Description: 剑指 Offer II 060. 出现频率最高的 k 个数字
 * @Author: Mr. Lee
 * @Date: 2021-08-30 10:16:04
 * @LastEditTime: 2021-08-30 10:49:54
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

static bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second > b.second;
}

vector<int> topKFrequent(vector<int> &nums, int k)
{
    vector<int> res;
    unordered_map<int, int> m;

    for (auto &num : nums)
    {
        m[num]++;
    }

    vector<pair<int, int>> b;
    for (auto &x : m)
    {
        b.push_back(x);
    }

    sort(b.begin(), b.end(), comp);

    for (int i = 0; i < k; i++)
    {
        res.push_back(b[i].first);
    }

    return res;
}

int main(void)
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> ans = topKFrequent(nums, k);
    for (int &num : ans)
        cout << num << " ";
    cout << endl;

    return 0;
}