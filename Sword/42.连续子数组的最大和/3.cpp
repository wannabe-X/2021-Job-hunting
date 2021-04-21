#include <iostream>
#include <vector>
using namespace std;

// 动态规划 原地修改
int maxSubArray(vector<int> &nums)
{
    int ans = nums[0];
    for(int i=1;i<nums.size();i++)
    {
        nums[i] += max(nums[i-1],0);
        ans = max(ans,nums[i]);
    }
    return ans;
}

int main(void)
{
    vector<int> nums = {-1,-2};
    int ans = maxSubArray(nums);
    cout << ans << endl;
    return 0;
}