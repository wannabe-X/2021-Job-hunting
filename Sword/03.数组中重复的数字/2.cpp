#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int findRepeatNumber(vector<int> &nums)
{
    unordered_set<int> mySet;

    for (int i = 0; i < nums.size(); i++)
    {
        if (mySet.count(nums[i]))
            return nums[i];
        else
            mySet.insert(nums[i]);
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