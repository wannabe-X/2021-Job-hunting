#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isStraight(vector<int> &nums)
{
    bool res = true;
    sort(nums.begin(), nums.end());

    int count = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == 0)
            count++;
        if (nums[i] == nums[i + 1] && nums[i] && nums[i + 1])
            res = false;
    }

    if (nums[4] - nums[count] > 4)
        res = false;

    return res;
}

int main(void)
{
    vector<int> nums = {1,2,0,0,5};
    bool ans = isStraight(nums);
    cout << ans << endl;
    return 0;
}