#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 快慢指针法
vector<int> exchange(vector<int> &nums)
{
    int slow = 0, fast = 0;
    while (fast < nums.size())
    {
        if (nums[fast] % 2)
        {
            swap(nums[slow],nums[fast]);
            slow++;
        }
        fast++;
    }
    return nums;
}

int main(void)
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans = exchange(nums);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    return 0;
}