#include <iostream>
#include <vector>

using namespace std;

vector<int> left_bound(vector<int> &nums, int target)
{
    int left = 0, right = nums.size();
    int flag = 0;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] < target)
            left = mid + 1;
        else if (nums[mid] == target)
        {
            flag = 1;
            right = mid;
        }
        else
            right = mid;
    }

    return {left, flag};
}

int search(vector<int> &nums, int target)
{
    vector<int> left = left_bound(nums, target);
    int count = 0;
    if (left[1] == 1)
        for (int i = left[0]; i < nums.size() && nums[i] == target; count += 1, i++)
            ;
    return count;
}

int main(void)
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 6;
    int ans = search(nums, target);
    cout << ans << endl;
    return 0;
}