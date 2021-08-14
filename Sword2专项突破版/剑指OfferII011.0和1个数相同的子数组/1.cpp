/*
 * @Description: 剑指 Offer II 011. 0 和 1 个数相同的子数组
 * @Author: Mr. Lee
 * @Date: 2021-08-14 11:51:32
 * @LastEditTime: 2021-08-15 00:10:22
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int findMaxLength(vector<int> &nums)
{
    unordered_map<int, int> mp;
    int preSum = 0, maxLen = 0;
    mp[0] = -1;
    for (int i = 0; i < nums.size(); ++i)
    {
        preSum += nums[i] ? 1 : -1;
        if (mp.find(preSum) != mp.end())
            maxLen = max(maxLen, i - mp[preSum]);
        else
            mp[preSum] = i;
    }
    return maxLen;
}

int main()
{
    vector<int> nums = {0, 1, 0};
    int ans = findMaxLength(nums);
    cout << ans << endl;
    
    return 0;
}