#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != i)
            return i;
    }
    return nums.size();
}

int main(void)
{
    vector<int> nums = {0};
    int ans = missingNumber(nums);
    cout << ans << endl;
}