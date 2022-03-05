/*
 * @Description:
 * @Author: Mr. Lee
 * @Date: 2022-03-05 09:54:37
 * @LastEditTime: 2022-03-05 10:58:12
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// int maxSum(vector<int> &nums)
// {
//     int sum = 0, tmp = 0;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (tmp > 0)
//             tmp += nums[i];
//         else
//             tmp = nums[i];
//         if (tmp > sum)
//             sum = tmp;
//     }

//     return sum;
// }

// int main(int argc, char *argv[])
// {
//     int n;
//     cin >> n;
//     vector<int> nums(n, 0);
//     int i = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int tmp;
//         cin >> tmp;
//         nums[i] = tmp;
//     }

//     int ans = maxSum(nums);
//     cout << ans << endl;

//     return 0;
// }

int maxSum1(vector<int> &nums)
{
    int sum = 0, tmp = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (tmp > 0)
            tmp += nums[i];
        else
            tmp = nums[i];
        if (tmp > sum)
            sum = tmp;
    }

    return sum;
}

int maxSum(vector<int> &nums)
{
    int len = nums.size(), tmpa = -100000, tmpb = 100000;
    int sum = 0;
    for (int i = 0; i < len - 1; i++)
    {
        sum += abs(nums[i] - nums[i + 1]);
        tmpa = max(tmpa, min(nums[i], nums[i + 1]));
        tmpb = min(tmpb, max(nums[i], nums[i + 1]));
    }
    sum = maxSum1(nums);
    int ans = max(sum, sum + (tmpa - tmpb) * 2);
    cout << ans << endl;
    // for (int i = 0; i < len - 1; i++)
    // {
    //     ans = max(ans, sum + abs(nums[0] - nums[i + 1]) - abs(nums[i] - nums[i + 1]));
    //     ans = max(ans, sum + abs(nums[len - 1] - nums[i + 1]) - abs(nums[i] - nums[i + 1]));
    // }

    return ans;
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        nums[i] = tmp;
    }

    int ans = maxSum(nums);
    cout << ans << endl;

    return 0;
}


