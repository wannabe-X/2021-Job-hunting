#include <iostream>
#include <vector>
#include <algorithm>

// 参考代码
using namespace std;

bool isStraight(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int count = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == 0)
            count++;
        else if (nums[i] == nums[i + 1])
            return false;
    }
    return nums[4] - nums[count] < 5;
}

int main(void)
{
    vector<int> nums = {1, 2, 0, 0, 5};
    bool ans = isStraight(nums);
    cout << ans << endl;
    return 0;
}