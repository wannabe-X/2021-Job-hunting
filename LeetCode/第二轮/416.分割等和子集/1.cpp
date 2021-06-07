#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canPartition(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0, target;
    for (int i = 0; i < n; sum += nums[i], i++)
        ;
    int maxNum = *max_element(nums.begin(), nums.end());
    target = sum / 2;
    if ((sum & 1) || n < 2 || maxNum > target)
        return false;
    /*
        创建二维数组 dp，包含 n 行 target+1 列，
        其中 dp[i][j] 表示从数组的[0,i] 下标范围内选取若干个正整数（可以是 0 个），
        是否存在一种选取方案使得被选取的正整数的和等于 j
    */
    vector<vector<int>> res(n, vector<int>(target + 1, 0));
    for (int i = 0; i < n; res[i][0] = 1, i++)
        ;
    res[0][nums[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < target + 1; j++)
        {
            if (j < nums[i])
                res[i][j] = res[i - 1][j];
            else
                res[i][j] = res[i - 1][j] | res[i - 1][j - nums[i]];
        }
    }

    return res[n - 1][target] == 1 ? true : false;
}

int main()
{
    // int n, idx = 0;
    // cin >> n;
    // vector<int> nums(n);
    // while (cin >> nums[idx++] && idx < n)
    //     ;
    vector<int> nums = {9, 5};
    bool ans = canPartition(nums);
    cout << boolalpha << ans << endl;
    return 0;
}