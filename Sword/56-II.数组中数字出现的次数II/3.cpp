#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 剑指offer参考解法
// 把数组每个数的二进制都取出来
// 统计数组中的数据每个二进制位中1的个数
// 三个相同的数字，那么每个二进制位的个数应该都可以被3整除
// 被3整除剩下的二进制位就是不重复数字的二进制
// 将二进制加起来即可

int digitCapacity(int n)
{
    int idx = 0;
    while (n)
    {
        n >>= 1;
        idx++;
    }
    return idx;
}

int singleNumber(vector<int> &nums)
{
    int maxVal = *max_element(nums.begin(), nums.end());
    int count = digitCapacity(maxVal);
    // cout << count << endl;
    vector<int> bitSum(count, 0);

    for (int num : nums)
    {
        long bitMask = 1;
        for (int j = count - 1; j > -1; j--)
        {
            int temp = num & bitMask;
            if (temp)
                bitSum[j] += 1;
            bitMask <<= 1;
        }
    }

    // 从前往后加
    int result = 0;
    for (int i = 0; i < count; i++)
    {
        result <<= 1;
        result += bitSum[i] % 3;
    }

    // 从后往前加

    // int result = 0, x = 1;
    // for (int i = 31; i > -1; i--)
    // {
    //     result += (x * (bitSum[i] % 3));
    //     x <<= 1;
    // }

    return result;
}

int main(void)
{
    vector<int> nums = {2147483647, 2147483647, 2147483647, 1};
    int ans = singleNumber(nums);
    cout << ans << endl;
    // for (int num : ans)
    //     cout << num << ' ';
    // cout << endl;
    return 0;
}