/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-10-09 18:59:25
 * @LastEditTime: 2021-10-09 20:50:59
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int func(int k, int x, vector<int> nums)
{
    int res = 1;
    vector<int> v;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i + 1] - nums[i] > x)
        {
            res++;
            v.push_back(nums[i + 1] - nums[i]);
        }
    }

    for (int i = 0; i < v.size() && k != 0; i++)
    {
        if (v[i] <= 2 * x)
        {
            res--;
            k--;
        }
    }

    return res;
}

int main(void)
{
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int ans = func(k, x, nums);
    cout << ans << endl;

    return 0;
}