#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> myMap;
    int sum_i = 0, ans = 0;
    myMap[0] = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        sum_i += nums[i];

        int sum_j = sum_i - k;
        if (myMap.count(sum_j))
            ans += myMap[sum_j];
            
        if (myMap.count(sum_i))
            myMap[sum_i] += 1;
        else
            myMap[sum_i] = 1;
    }
    return ans;
}

int main(void)
{
    vector<int> nums = {1, 1, 1};
    int k = 2;
    int ans = subarraySum(nums, k);
    std::cout << ans << endl;
}
