/*
 * @Description: 剑指 Offer II 067. 最大的异或
 * @Author: Mr. Lee
 * @Date: 2021-09-02 15:14:42
 * @LastEditTime: 2021-09-02 15:28:22
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMaximumXOR(vector<int> &nums)
{
    int res = 0;
    for (auto &num : nums)
    {
        for (auto &num1 : nums)
        {
            res = max(res, num ^ num1);
        }
    }

    return res;
}

int main(void)
{
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    int ans = findMaximumXOR(nums);
    cout << ans << endl;

    return 0;
}