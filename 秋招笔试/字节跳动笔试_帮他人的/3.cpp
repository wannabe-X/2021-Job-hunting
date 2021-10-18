/*
 * @Description:
 * @Author: Mr. Lee
 * @Date: 2021-10-17 19:24:04
 * @LastEditTime: 2021-10-18 09:21:17
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>

using namespace std;

int func(vector<int> nums, int m)
{
    vector<pair<int, bool>> v, tmp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i + 1 == m)
            tmp.push_back({nums[i], true});
        else
            tmp.push_back({nums[i], false});
    }

    int n = nums.size();
    int res = 1;

    while (n--)
    {
        v = tmp;

        if (v[0].second == true)
            return res;

        int min_ = INT8_MAX, min_idx = 0;

        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].first < min_)
            {
                min_ = v[i].first;
                min_idx = i;
            }
        }

        tmp.clear();
        for (int k = min_idx + 1; k < v.size(); k++)
            tmp.push_back(v[k]);
        for (int k = 0; k < min_idx; k++)
            tmp.push_back(v[k]);

        res++;
    }

    return res;
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int ans = func(nums, m);
    cout << ans;

    return 0;
}