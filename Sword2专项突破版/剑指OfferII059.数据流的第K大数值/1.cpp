/*
 * @Description: 剑指 Offer II 059. 数据流的第 K 大数值
 * @Author: Mr. Lee
 * @Date: 2021-08-30 09:16:05
 * @LastEditTime: 2021-08-30 10:09:46
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class KthLargest
{
public:
    KthLargest(int k, vector<int> &nums)
    {
        Kth = k;
        for (auto &num : nums)
            add(num);
    }

    int add(int val)
    {
        q.push(val);
        if (q.size() > Kth)
            q.pop();

        return q.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> q;
    int Kth;
};

int main(void)
{
    return 0;
}