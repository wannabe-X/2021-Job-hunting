#include <iostream>
#include <vector>

using namespace std;
int subarraySum(vector<int> &nums, int k)
{
    vector<int> sum(nums.size() + 1, 0);
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum[i + 1] = sum[i] + nums[i];
    }

    for (int i = 1; i <= nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (sum[i] - sum[j] == k)
                ans++;
        }
    }

    return ans;
}

int main(void)
{
    vector<int> nums = {1, 1, 1};
    int k = 2;
    int ans = subarraySum(nums, k);
    cout << ans << endl;
}
