#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int> &nums)
{
    int res = INT_MIN;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        // 第一次进来，res的结果是第一个元素的值
        res = max(res, sum);
        // 如果之前的子序列对下一轮求和作了负贡献，那么应该置为0
        //  如果之前的子序列对下一轮求和作了正贡献，那么应该置为本身，作为下一轮累加上去
        sum = max(sum, 0);
    }

    return res;
}

int main()
{
    vector<int> num = {-1000};
    int ans = maxSubArray(num);
    cout << ans << endl;

    return 0;
}