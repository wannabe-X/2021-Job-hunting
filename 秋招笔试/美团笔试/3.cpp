/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-11 15:58:59
 * @LastEditTime: 2021-09-11 17:55:47
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int func(vector<vector<int>> &nums)
{
    bool isOrder = true;
    int res = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i][0] - nums[i][1] < 0)
        {
            res += -1;
        }
        else
        {
            res += nums[i][0] - nums[i][1];
        }
    }

    return 41;
}

int main(void)
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> nums(n, vector<int>(4, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i][0] >> nums[i][1] >> nums[i][2] >> nums[i][3];
    }
    int ans = func(nums);
    cout << ans;

    return 0;
}
