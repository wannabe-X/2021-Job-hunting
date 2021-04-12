#include <iostream>
#include <vector>

using namespace std;

// ʹ��λ���㣨������㣩������
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