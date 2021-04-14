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
        // 把元素nums[i]放到索引对应的位置上，例如
        // nums[i] = 3,执行以下语句后，nums数组中，第四个元素即为3
        // 每执行一次swap，就有一个元素被放到了索引对应的位置，被校正
        // nums[nums[i]]就被放置了nums[i]
        swap(nums[nums[i]], nums[i]);
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