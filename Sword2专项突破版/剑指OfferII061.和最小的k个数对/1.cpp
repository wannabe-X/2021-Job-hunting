/*
 * @Description: 剑指 Offer II 061. 和最小的 k 个数对
 * @Author: Mr. Lee
 * @Date: 2021-08-30 10:51:04
 * @LastEditTime: 2021-08-30 11:51:21
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        // 最小堆
        auto cmp = [&](const pair<int, int> &lhs, const pair<int, int> &rhs)
        {
            return nums1[lhs.first] + nums2[lhs.second] > nums1[rhs.first] + nums2[rhs.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(cmp);

        for (int i = 0; i < k && i < nums1.size(); ++i)
        {
            heap.push({i, 0});
        }

        vector<vector<int>> ret;
        
        while (k-- > 0 && !heap.empty())
        {
            auto ids = heap.top();
            heap.pop();
            ret.push_back({nums1[ids.first], nums2[ids.second]});

            if (ids.second < nums2.size() - 1)
            {
                heap.push({ids.first, ids.second + 1});
            }
        }

        return ret;
    }
};

int main(void)
{
    vector<int> nums1 = {1, 7, 11}, nums2 = {2, 4, 6};
    int k = 3;
    return 0;
}