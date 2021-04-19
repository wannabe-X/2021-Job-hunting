#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 解法2 使用投票法
int majorityElement(vector<int> &nums)
{
    int count = 0, candicate = 0;
    for (int n : nums)
    {
        if (count == 0)
            candicate = n;

        if (n == candicate)
            count++;
        else
            count--;
    }
    return candicate;
}

int main(void)
{
    vector<int> nums = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    int ans = majorityElement(nums);
    cout << ans << endl;
    return 0;
}