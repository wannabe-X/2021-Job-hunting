#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> mymap;
    vector<int> res(nums1.size(), -1);
    stack<int> s;
    for (int i = nums2.size() - 1; i > -1; i--)
    {
        while (!s.empty() && s.top() <= nums2[i])
        {
            s.pop();
        }

        mymap[nums2[i]] = s.empty() ? -1 : s.top();
        s.push(nums2[i]);
    }

    for (int i = 0; i < nums1.size(); i++)
    {
        if (mymap.count(nums1[i]))
            res[i] = mymap[nums1[i]];
    }

    return res;
}

int main(void)
{
    vector<int> nums1 = {4,1,2}, nums2 = {1,3,4,2};
    vector<int> ans = nextGreaterElement(nums1, nums2);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}