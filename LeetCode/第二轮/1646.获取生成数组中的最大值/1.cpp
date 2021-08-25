/*
 * @Description: 1646. 获取生成数组中的最大值
 * @Author: Mr. Lee
 * @Date: 2021-08-23 11:09:25
 * @LastEditTime: 2021-08-23 11:21:27
 * @LastEditors: Mr. Lee
 */
#include <vector>
#include <iostream>

using namespace std;

int getMaximumGenerated(int n)
{
    if (n == 0)
        return 0;

    vector<int> nums(n+1);
    nums[0] = 0, nums[1] = 1;
    int numMax = 1;
    for (int i = 2; i <= n; i++)
    {
        nums[i] = nums[i / 2];
        if (i & 1)
        {
            nums[i] += nums[i / 2 + 1];
        }
        numMax = max(numMax, nums[i]);
    }

    return numMax;
}

int main()
{
    int n = 100;
    int ans = getMaximumGenerated(n);
    cout << ans << endl;

    return 0;
}
