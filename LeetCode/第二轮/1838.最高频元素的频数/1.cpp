/*
 * @Description: 1838. 最高频元素的频数
 * @Author: Mr. Lee
 * @Date: 2021-07-19 00:18:59
 * @LastEditTime: 2021-07-19 01:00:29
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int maxFrequency(vector<int> &nums, int k)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int res = 0, L = 0;
    long long window_sum = 0; // 注意这里的类型，不能用int，否则会溢出
    for (int R = 0; R < n; R++)
    {   
        window_sum += nums[R];
        // 寻找左边界
        while (window_sum + k < (long long)(nums[R] * (R - L + 1)))
        {
            window_sum -= nums[L];
            L++;
        }
        res = max(res, R - L + 1);
    }
    return res;
}

int main()
{
    vector<int> nums{1, 2, 4};
    int k = 5;
    int ans = maxFrequency(nums, k);
    cout << ans << endl;

    return 0;
}