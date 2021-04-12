#include <iostream>
#include <vector>
using namespace std;
vector<int> res;

vector<int> twoSum(vector<int> &nums, int target)
{

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (target == nums[i] + nums[j])
            {
                res.push_back(i);
                res.push_back(j);
                return res;
            }
        }
    }
    return {-1,-1};
}

int main(void)
{
    vector<int> nums = {3, 2, 4};
    int target = 10;

    vector<int> ans = twoSum(nums, target);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
        cout << endl;
    }
}
