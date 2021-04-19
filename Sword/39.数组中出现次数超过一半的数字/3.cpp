# include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 解法3 使用排序 那么位数超过半数的数字一定在中间位置
int majorityElement(vector<int> &nums)
{
    sort(nums.begin(),nums.end());
    return nums[nums.size()/2];
}

int main(void)
{
    vector<int> nums = {0};
    int ans = majorityElement(nums);
    cout << ans << endl;
    return 0;
}