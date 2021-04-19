#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 解法1 使用map字典
int majorityElement(vector<int> &nums)
{
    unordered_map<int, int> myMap;
    for (int i = 0; i < nums.size(); i++)
    {
        if (myMap.count(nums[i]))
        {
            myMap[nums[i]] += 1;
            continue;
        }
        else
            myMap[nums[i]] = 1;
    }

    for (auto it = myMap.begin(); it != myMap.end(); it++)
    {
        if (it->second > nums.size() / 2)
            return it->first;
    }
    return nums.size();
}

int main(void)
{
    vector<int> nums = {0};
    int ans = majorityElement(nums);
    cout << ans << endl;
    return 0;
}