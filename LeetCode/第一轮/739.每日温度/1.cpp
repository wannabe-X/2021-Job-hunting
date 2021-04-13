#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(vector<int> &T)
{
    vector<int> res(T.size());
    stack<int> s;
    // s中存放的是下标，下标对应的元素值是单调的
    for (int i = T.size() - 1; i > -1; i--)
    {
        while (!s.empty() && T[s.top()] <= T[i])
            s.pop();
        res[i] = s.empty() ? 0 : s.top() - i;
        s.push(i);
    }
    return res;
}

int main(void)
{
    vector<int> nums1 = {2, 4}, nums2 = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans = dailyTemperatures(nums2);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}