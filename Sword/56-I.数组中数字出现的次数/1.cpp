#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> singleNumbers(vector<int> &nums)
{
    vector<int> ans;
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
            ans.push_back(it->first);
    }
    return ans;
}

int main(void)
{
    vector<int> nums = {4,4};
    vector<int> ans = singleNumbers(nums);
    for (int num : ans)
        cout << num << ' ';
    cout << endl;
    return 0;
}