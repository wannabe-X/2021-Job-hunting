#include <iostream>
#include <vector>

using namespace std;

// 使用位运算（异或运算）操作符
int findDisappearedNumbers(vector<int> &nums)
{
    int n = nums.size(), res = 0;
    for (int i = 0; i <= n; i++)
    {
        res ^= (i ^ nums[i]);
    }
    return res;
}

int main(void)
{
    vector<int> nums = {0, 3, 1, 4};
    int ans = findDisappearedNumbers(nums);
    cout << ans << endl;
}