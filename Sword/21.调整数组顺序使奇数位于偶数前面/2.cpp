#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 双指针法
vector<int> exchange(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;
    while (left < right)
    {
        if (nums[left] % 2)
        {
            left++;
            continue;
        }
        if (nums[right] % 2 == 0)
        {
            right--;
            continue;
        }
        swap(nums[left++], nums[right--]);
    }

    return nums;
}

int main(void)
{
    vector<int> nums = {1, 2, 3, 4, 6, 7, 8, 9, 10, 11};
    vector<int> ans = exchange(nums);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    return 0;
}