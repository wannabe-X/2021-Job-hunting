/*
 * @Description: 剑指 Offer II 071. 按权重生成随机数
 * @Author: Mr. Lee
 * @Date: 2021-09-03 01:05:01
 * @LastEditTime: 2021-09-03 01:20:01
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

class Solution
{
public:
    Solution(vector<int> &w)
    {
        preSum.push_back(w[0]);
        for (int i = 1; i < w.size(); i++)
            preSum.push_back(preSum.back() + w[i]);
    }

    int pickIndex()
    {
        int random = rand() % preSum.back() + 1;
        return lower_bound(preSum.begin(), preSum.end(), random)-preSum.begin();
    }

private:
    vector<int> preSum;
};

int main(void)
{
    return 0;
}