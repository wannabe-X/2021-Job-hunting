/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-10-13 21:34:39
 * @LastEditTime: 2021-10-13 22:00:45
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int func(vector<int> &nums)
{
    int max1 = INT8_MIN, max2 = INT8_MIN, max3 = INT8_MIN;
    int idx1 = 0, idx2 = 0, idx3 = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > max1)
        {
            max1 = nums[i];
            idx1 = i;
        }
    }

    for (int i = 0; i < idx1; i++)
    {
        if (nums[i] > max2)
        {
            max2 = nums[i];
            idx2 = i;
        }
    }

    for (int i = 0; i < idx2; i++)
    {
        if (nums[i] > max3)
        {
            max3 = nums[i];
            idx3 = i;
        }
    }

    if (!(max1 > max2 && max2 > max3 && idx1 > idx2 && idx2 > idx3))
        return 0;

    return max1 + max2 + max3;
}

int main(void)
{
    int N;
    cin >> N;
    vector<int> nums(N, 0);
    for (int i = 0; i < N; i++)
        cin >> nums[i];
    int ans = func(nums);
    cout << ans << endl;

    return 0;
}