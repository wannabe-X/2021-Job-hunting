#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    vector<int> top(nums.size(), 0);
    int piles = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        int poker = nums[i];
        int left = 0, right = piles;

        while (left < right)
        {
            int mid = (left + right) / 2;
            if (top[mid] == poker)
                right = mid;
            else if (top[mid] < poker)
                left = mid + 1;
            else if (top[mid] > poker)
                right = mid;
        }

        if (left == piles)
            piles++;
        top[left] = poker;
    }

    return piles;
}

int main(void)
{
    vector<int> nums = {1,2,3,4,5,6};
    int res = lengthOfLIS(nums);
    cout << res << endl;
}