/*
 * @Description:
 * @Author: Mr. Lee
 * @Date: 2022-03-05 09:54:32
 * @LastEditTime: 2022-03-05 11:47:34
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int func(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> v(n);
    int r = 0;
    v[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1])
            continue;
        if (nums[i] - nums[r] > 1)
        {
            r++;
            v[r] = nums[i];
        }
        else
        {
            int left = 0, right = r;
            while (left < right)
            {
                int mid = left + (right - left) / 2;
                if (v[mid] < nums[i] + 1)
                    left = mid + 1;
                else
                    right = mid;
            }
            v[left] = nums[i];
        }
    }
    return r;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        nums[i] = tmp;
    }

    int ans = func(nums);
    cout << ans;

    return 0;
}