/*
 * @Description: 剑指 Offer II 010. 和为 k 的子数组
 * @Author: Mr. Lee
 * @Date: 2021-08-14 11:17:02
 * @LastEditTime: 2021-08-14 11:52:52
 * @LastEditors: Mr. Lee
 */

// 参考解法，hash+前缀和

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    int res = 0, sum = 0;
    unordered_map<int, int> dict;
    dict[0] = 1;

    for (const int &num : nums)
    {
        sum += num;
        if (dict.count(sum - k))
            res += dict[sum - k];
        dict[sum]++;
    }

    return res;
}

int main()
{
    vector<int> nums = {-1, -1, 1};
    int k = 0;
    int ans = subarraySum(nums, k);
    cout << ans << endl;

    return 0;
}