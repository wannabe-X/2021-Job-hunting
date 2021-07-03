/*
 * @Description: 645. 错误的集合
 * @Author: Mr. Lee
 * @Date: 2021-07-04 00:28:03
 * @LastEditTime: 2021-07-04 00:54:04
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findErrorNums(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int repeat = nums[0];
    int exclusive = 0;

    // 找出重复的元素
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i - 1] == nums[i])
        {
            repeat = nums[i];
            break;
        }
    }
    
    // 使用异或运算，找出缺失的元素值
    for (int i = 1; i <= nums.size(); i++)
    {
        exclusive ^= (nums[i - 1] ^ i);
    }

    return {repeat, exclusive ^ repeat};
}

int main()
{
    vector<int> nums = {1,1};
    vector<int> ans = findErrorNums(nums);
    cout << "[" << ans[0] << "," << ans[1] << "]" << endl;

    return 0;
}
