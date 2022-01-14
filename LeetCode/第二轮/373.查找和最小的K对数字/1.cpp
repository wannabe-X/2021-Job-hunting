/*
 * @Description: 373.查找和最小的K对数字
 * @Author: Mr. Lee
 * @Date: 2022-01-14 16:30:12
 * @LastEditTime: 2022-01-14 17:44:53
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
    auto cmp = [&nums1, &nums2](const pair<int, int> &a, const pair<int, int> &b)
    {
        return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
    };

    vector<vector<int>> res = {};
    int m = nums1.size(), n = nums2.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < min(k, m); i++)
        pq.emplace(i, 0);
    while (k-- && !pq.empty())
    {
        // auto [x,y] = pq.top();
        int x = pq.top().first, y = pq.top().second;
        pq.pop();
        res.emplace_back(initializer_list<int>{nums1[x], nums2[y]});
        if (y + 1 < n)
            pq.emplace(x, y + 1);
    }

    return res;
}

int main(int argc, char *argv[])
{
    vector<int> nums1 = {1, 1, 2}, nums2 = {1, 2, 3};
    int k = 6;
    vector<vector<int>> ans = kSmallestPairs(nums1, nums2, k);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i][0] << " " << ans[i][1] << endl;

    return 0;
}