/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-07-08 01:19:10
 * @LastEditTime: 2021-07-08 01:19:46
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <numeric>
#include <unordered_map>

using namespace std;

int numSubarraysWithSum(vector<int> &nums, int goal)
{
    int sum = 0;
    unordered_map<int, int> cnt;
    int ret = 0;
    for (auto &num : nums)
    {
        cnt[sum]++;
        sum += num;
        ret += cnt[sum - goal];
    }
    return ret;
}

int main()
{
    vector<int> nums = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0};
    int goal = 0;
    int ans = numSubarraysWithSum(nums, goal);
    cout << ans << endl;

    return 0;
}