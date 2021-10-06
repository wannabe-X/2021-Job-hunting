/*
 * @Description: 414. 第三大的数
 * @Author: Mr. Lee
 * @Date: 2021-10-06 16:21:00
 * @LastEditTime: 2021-10-06 17:01:07
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <queue>

using namespace std;

int thirdMax(vector<int> &nums)
{
    unordered_set<int> seen;
    priority_queue<int, vector<int>, less<int>> pq;
    for (int num : nums)
    {
        if (!seen.count(num))
        {
            seen.insert(num);
            pq.push(num);
        }
    }

    if (pq.size() < 3)
        return pq.top();
        
    pq.pop(), pq.pop();

    return pq.top();
}

int main(void)
{
    vector<int> nums = {1, 2, 2, 5, 3, 5};
    int ans = thirdMax(nums);
    cout << ans << endl;

    return 0;
}