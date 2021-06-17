/*
 * @Description: 连续子数组的最大和
 * @Author: Mr. Lee
 * @Date: 2021-06-17 15:15:06
 * @LastEditTime: 2021-06-17 15:44:37
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

int FindGreatestSumOfSubArray(vector<int> array)
{
    int tmp = 0, res = INT_MIN;
    for (auto num : array)
    {
        tmp += num;
        res = max(res, tmp);

        // (tmp = max(0, tmp)) 相当于 tmp = tmp > 0 ? tmp : 0;
        // 如果当前数字对求和的贡献小于0，那么就按照0来计算贡献
        tmp = max(0, tmp);
    }

    return res;
}

int main()
{
    // 测试用例
    // vector<int> nums = {1, -2, 3, 10, -4, 7, 2, -5};

    int numofarray, idx = 0;
    cin >> numofarray;
    vector<int> nums(numofarray);
    while(idx<numofarray && cin>>nums[idx++]);
    int ans = FindGreatestSumOfSubArray(nums);

    cout << ans << endl;

    return 0;
}
