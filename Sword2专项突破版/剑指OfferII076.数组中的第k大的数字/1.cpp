/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-06 09:52:56
 * @LastEditTime: 2021-09-06 10:07:41
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> q;
    for (auto &num : nums)
    {
        if (q.size() < k)
            q.push(num);
        else if (q.top() <= num)
        {
            q.pop();
            q.push(num);
        }
    }

    return q.top();
}

int main(void)
{
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    int ans = findKthLargest(nums, k);
    cout << ans << endl;

    return 0;
}