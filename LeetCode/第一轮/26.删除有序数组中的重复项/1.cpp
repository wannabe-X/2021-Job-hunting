#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int> &nums)
{
    if(nums.empty()) return 0;
    int slow = 0, fast = 1;
    while (fast < nums.size())
    {
        if (nums[slow] != nums[fast])
        {
            slow++;
            nums[slow] = nums[fast];
        }
        fast++;
    }
    return slow+1;
}

int main(void)
{
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int ans = removeDuplicates(nums);
    cout << ans << endl;
}