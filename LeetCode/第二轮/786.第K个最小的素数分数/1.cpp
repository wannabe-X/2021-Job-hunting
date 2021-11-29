/*
 * @Description: 786.第K个最小的素数分数
 * @Author: Mr. Lee
 * @Date: 2021-11-29 00:44:09
 * @LastEditTime: 2021-11-29 09:47:41
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const pair<int, int> &x, const pair<int, int> &y)
{
    return x.first * y.second < y.first * x.second;
}

vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
            v.emplace_back(arr[i], arr[j]);
    }

    sort(v.begin(), v.end(), comp);

    // sort(v.begin(), v.end(), [](const pair<int, int> &x, const pair<int, int> &y)
    //      { return x.first * y.second < y.first * x.second; });

    return {v[k - 1].first, v[k - 1].second};
}

int main(int argc, char *argv[])
{
    vector<int> arr = {1, 2, 3, 5};
    int k = 3;
    vector<int> ans = kthSmallestPrimeFraction(arr, k);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}