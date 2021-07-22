/*
 * @Description: 1877. 数组中最大数对和的最小值
 * @Author: Mr. Lee
 * @Date: 2021-07-20 00:09:12
 * @LastEditTime: 2021-07-20 00:29:15
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minPairSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int i = nums.size() / 2 - 1, j = nums.size() / 2;
    int res = 0;
    while (i >= 0 && j < nums.size())
    {
        int sum = nums[i--] + nums[j++];
        res = max(res, sum);
    }

    return res;
}

int main()
{
    vector<int> nums = {3,5,4,2,4,6};
    int ans = minPairSum(nums);
    cout << ans << endl;

    return 0;
}
