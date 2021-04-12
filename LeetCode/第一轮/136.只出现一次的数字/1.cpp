#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int res = 0;
    for (int num : nums)
        res ^= num;
    return res;
}

int main(void)
{
    vector<int> nums = {4, 1, 2, 1, 2};
    int ans = singleNumber(nums);
    cout << ans << endl;
}