/*
 * @Description: 260. 只出现一次的数字 III
 * @Author: Mr. Lee
 * @Date: 2021-10-30 10:18:11
 * @LastEditTime: 2021-10-30 11:30:20
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> singleNumber(vector<int> &nums)
{
    int sum = 0;
    for (int num : nums)
        sum ^= num;

    int classification = (sum == INT_MIN ? sum : sum & (-sum));

    int res1 = 0, res2 = 0;
    for (int num : nums)
    {
        if (num & classification)
            res1 ^= num;
        else
            res2 ^= num;
    }

    return {res1, res2};
}

int main(void)
{
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    vector<int> ans = singleNumber(nums);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}