#include <iostream>
#include <vector>

using namespace std;

int findRepeatNumber(vector<int> &nums)
{
    int i = 0;
    while (i < nums.size())
    {
        if (nums[i] == i)
        {
            i++;
            continue;
        }
        if (nums[nums[i]] == nums[i])
            return nums[i];
        swap(nums[i], nums[nums[i]]);
    }
    return -1;
}

int main(void)
{
    vector<int> nums = {2, 3, 1, 0, 2, 5, 3};
    int ans = findRepeatNumber(nums);
    cout << ans << endl;
    return 0;
}