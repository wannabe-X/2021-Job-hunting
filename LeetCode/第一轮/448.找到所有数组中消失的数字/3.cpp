#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findDisappearedNumbers(vector<int> &nums)
{
    int n = *max_element(nums.begin(), nums.end());
    int sum = n * (n + 1) / 2, except = 0;
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        except += nums[i];
    }

    return sum - except;
}

int main(void)
{
    vector<int> nums = {1, 2, 4};
    int ans = findDisappearedNumbers(nums);
    cout << ans << endl;
}