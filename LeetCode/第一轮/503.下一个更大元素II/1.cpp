#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreaterElement(vector<int> &nums)
{
    vector<int> res(nums.size());
    stack<int> s;
    int n = nums.size();
    for (int i = 2 * n - 1; i > -1; i--)
    {
        int k = i % n;
        while (!s.empty() && s.top() <= nums[k])
        {
            s.pop();
        }

        res[k] = s.empty() ? -1 : nums[k];

        s.push(nums[k]);
    }
    return res;
}

int main(void)
{
    vector<int> nums = {2, 4};
    vector<int> ans = nextGreaterElement(nums);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}