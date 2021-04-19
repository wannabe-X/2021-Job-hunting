#include <iostream>
#include <vector>

using namespace std;

// 解法2 参考代码  利用二分法
// 采用左闭右开的二分法 
// left最终指向缺失元素的下标
int missingNumber(vector<int> &nums)
{
    int left = 0, right = nums.size();
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == mid)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int main(void)
{
    vector<int> nums = {0,1,3};
    int ans = missingNumber(nums);
    cout << ans << endl;
}