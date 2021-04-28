#include <iostream>
#include <vector>

using namespace std;
// 暴力破解 逐个扫描
int reversePairs(vector<int> &nums)
{
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
            if (nums[i] < nums[j])
                count++;
    }
    return count;
}

int main(void)
{
    vector<int> nums = {7, 5, 6, 4};
    int ans = reversePairs(nums);
    cout << ans << endl;
    return 0;
}