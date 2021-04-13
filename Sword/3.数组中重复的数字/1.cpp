#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findRepeatNumber(vector<int> &nums)
{
    unordered_map<int, int> myMap;

    for (int i = 0; i < nums.size(); i++)
    {
        if (myMap.count(nums[i]))
        {
            myMap[nums[i]] += 1;
        }
        else
        {
            myMap[nums[i]] = 1;
        }
    }

    int res = -1;

    for (auto iter = myMap.begin(); iter != myMap.end(); ++iter)
    {
        if (iter->second > 1)
            {
                res = iter->first;
                break;
            }
    }

    return res;
}

int main(void)
{
    vector<int> nums = {2, 3, 1, 0, 2, 5, 3};
    int ans = findRepeatNumber(nums);
    cout << ans << endl;
    return 0;
}