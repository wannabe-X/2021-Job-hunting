/*
 * @Description: 528. 按权重随机选择
 * @Author: Mr. Lee
 * @Date: 2021-08-30 00:23:59
 * @LastEditTime: 2021-08-30 01:10:09
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

// 前缀和 + 二分
// 与水塘抽样算法不同
using namespace std;

class Solution
{
public:
    Solution(vector<int> &w)
    {
        sum = 0;
        preSum.push_back(w[0]);

        for (int i = 1; i < w.size(); i++)
        {
            preSum.push_back(preSum.back() + w[i]);
        }
        sum = preSum.back();
    }

    int pickIndex()
    {
        int target = rand() % sum + 1;

        int left = 0, right = preSum.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (preSum[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }

private:
    int sum;
    vector<int> preSum;
};

int main(void)
{
    return 0;
}