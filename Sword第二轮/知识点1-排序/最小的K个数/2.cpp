/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-06-10 17:34:47
 * @LastEditTime: 2021-06-10 17:44:08
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
    vector<int> ret;
    if (k == 0 || k > input.size())
        return ret;

    // 建立一个大根堆
    priority_queue<int, vector<int>, less<int>> big_top;
    for (const int num : input)
    {
        if (big_top.size() < k)
            big_top.push(num);
        else if (num < big_top.top())
        {
            big_top.pop();
            big_top.push(num);
        }
    }

    while (!big_top.empty())
    {
        ret.push_back(big_top.top());
        big_top.pop();
    }

    return ret;
}

int main()
{
    // 测试用例
    vector<int> nums = {4, 5, 1, 6, 2, 7, 3, 8};
    int k = 4;
    vector<int> ans = GetLeastNumbers_Solution(nums, k);

    // 手动输入
    // int k, num_len, idx = 0;
    // cin >> k >> num_len;
    // vector<int> nums(num_len);
    // while (cin >> nums[idx++] && idx < num_len)
    //     ;
    // 获取结果
    // vector<int> ans = GetLeastNumbers_Solution(nums, k);

    for (int num : ans)
    {
        cout << num << " ";
    }
    return 0;
}
