/*
 * @Description: 剑指 Offer II 070. 排序数组中只出现一次的数字
 * @Author: Mr. Lee
 * @Date: 2021-09-02 11:22:58
 * @LastEditTime: 2021-09-02 14:36:47
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 异或
// int singleNonDuplicate(vector<int> &nums)
// {
//     int res = 0;
//     for (auto &num : nums)
//         res ^= num;

//     return res;
// }

// 时间复杂度为o(logn),空间复杂度为o(1) 二分查找
int singleNonDuplicate(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;
}

int main(void)
{
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    int ans = singleNonDuplicate(nums);
    cout << ans << endl;

    return 0;
}