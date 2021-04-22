#include <iostream>
#include <map>
#include <vector>

using namespace std;

int singleNumber(vector<int> &nums)
{
    int ans;
    map<int, int> myMap;
    for (int num : nums)
    {
        if (myMap.count(num))
            myMap[num] += 1;
        else
            myMap[num] = 1;
    }

    for (auto it = myMap.begin(); it != myMap.end(); it++)
    {
        if (it->second < 2)
           {
               ans = it->first;
               break;
           }
    }
    return ans;
}

int main(void)
{
    vector<int> nums = {1};
    int ans = singleNumber(nums);
cout << ans<<endl;
    return 0;
}