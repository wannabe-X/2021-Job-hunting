#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void oddForward(vector<int> &nums, int idx)
{
    for (int i = idx; i > 0; i--)
        swap(nums[i], nums[i - 1]);
}

vector<int> exchange(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 2)
            oddForward(nums, i);
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