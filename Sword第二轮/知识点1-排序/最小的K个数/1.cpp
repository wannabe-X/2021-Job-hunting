/*
 * @Description: 剑指 Offer 40. 最小的k个数。直接排序，然后去前k小数据。
 * @Author: Mr. Lee
 * @Date: 2021-06-10 17:09:29
 * @LastEditTime: 2021-06-21 11:37:06
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
    vector<int> ret;
    if (k == 0 || k > input.size())
        return ret;
    sort(input.begin(), input.end());
    return vector<int>({input.begin(), input.begin() + k});
}

int main()
{
    // 测试用例
    // vector<int> nums = {4, 5, 1, 6, 2, 7, 3, 8};
    // int k = 4;
    // vector<int> ans = GetLeastNumbers_Solution(nums, k);

    // 手动输入
    int k, num_len, idx = 0;
    cin >> k >> num_len;
    vector<int> nums(num_len);
    while (cin >> nums[idx++] && idx < num_len)
        ;

    // 获取结果
    vector<int> ans = GetLeastNumbers_Solution(nums, k);
    for (int num : ans)
    {
        cout << num << " ";
    }
    return 0;
}
