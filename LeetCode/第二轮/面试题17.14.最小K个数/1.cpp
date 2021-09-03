/*
 * @Description: 面试题 17.14. 最小K个数
 * @Author: Mr. Lee
 * @Date: 2021-09-03 00:03:34
 * @LastEditTime: 2021-09-03 00:09:08
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> smallestK(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> q;
    for (const auto &num : arr)
        q.push(num);

    vector<int> res;
    for (int i = 0; i < k; i++)
    {
        res.push_back(q.top());
        q.pop();
    }

    return res;
}

int main(void)
{
    vector<int> arr = {1, 3, 5, 7, 2, 4, 6, 8};
    int k = 4;

    vector<int> ans = smallestK(arr, k);
    for (auto &num : ans)
        cout << num << " ";

    return 0;
}