/*
 * @Description: 581. 最短无序连续子数组。排序+双指针
 * @Author: Mr. Lee
 * @Date: 2021-08-03 13:05:49
 * @LastEditTime: 2021-08-03 13:35:16
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// int findUnsortedSubarray(vector<int> &nums)
// {
//     vector<int> tmp = nums;
//     unordered_map<int, int> m;
//     sort(tmp.begin(), tmp.end());

//     int left = 0, right = nums.size() - 1;

//     while (left < right && m[right - left] < 2)
//     {
//         if (left < right && nums[left] == tmp[left])
//             left++;
//         if (left < right && nums[right] == tmp[right])
//             right--;

//         m[right - left] += 1;
//     }

//     return right == left ? 0 : right - left + 1;
// }

int findUnsortedSubarray(vector<int> &nums)
{
    vector<int> tmp = nums;
    sort(tmp.begin(), tmp.end());

    int left = 0, right = nums.size() - 1;

    while (left <= right && nums[left] == tmp[left])
        left++;
    while (left <= right && nums[right] == tmp[right])
        right--;

    return right - left + 1;
}

int main()
{
    // vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
    // vector<int> nums = {1, 2, 3, 4};

    vector<int> nums;
    int tmp;
    while (cin >> tmp)
    {
        nums.push_back(tmp);
        if (cin.get() == '\n')
            break;
    }

    int ans = findUnsortedSubarray(nums);
    cout << ans << endl;

    return 0;
}
