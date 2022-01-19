/*
 * @Description: 219. 存在重复元素 II
 * @Author: Mr. Lee
 * @Date: 2022-01-19 10:40:24
 * @LastEditTime: 2022-01-19 10:52:41
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        if (m.count(nums[i]) && (i - m[nums[i]] <= k))
            return true;
        m[nums[i]] = i;
    }
    return false;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;
    bool ans = containsNearbyDuplicate(nums, k);
    cout << boolalpha << ans << endl;

    return 0;
}