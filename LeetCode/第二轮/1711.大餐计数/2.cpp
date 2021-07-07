/*
 * @Description: 大餐计数。参考解法
 * @Author: Mr. Lee
 * @Date: 2021-07-07 01:03:52
 * @LastEditTime: 2021-07-07 15:54:22
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <math.h>

using namespace std;

const int MOD = 1e9 + 7;

int countPairs(vector<int> &deliciousness)
{
    unordered_map<int, int> m;
    long long ans = 0;
    int target;
    /*     1 <= deliciousness.length <= 10^5
    0 <= deliciousness[i] <= 2^20
    因此，两个元素之和最大为2^21
    所以，第二个for循环当中，j<22; target最大到2^21 */
    for (int i = 0; i < deliciousness.size(); i++)
    {
        target = 1;
        /*         由于遍历数组时，哈希表中已有的元素的下标一定小于当前元素的下标，
        因此任意一对元素之和等于 22 的幂的元素都不会被重复计算。 */
        for (int j = 0; j < 22; target <<= 1, j++)
        {
            if (target - deliciousness[i] < 0)
                continue;
            /* 如果某一个deliciousness[i]==0，那么target - deliciousness[i] >= 1，
            target - deliciousness[i] 不会出现为0的情况，因此[0,0]组合的元素对不会被统计 */
            if (m.count(target - deliciousness[i]))
                ans += m[target - deliciousness[i]];
        }

        // 每次走完一个元素，都将其出现的次数记录在map中
        m[deliciousness[i]]++;
    }

    ans %= MOD;
    return ans;
}

int main()
{
    vector<int> deliciousness = {2160, 1936, 3, 29, 27, 5,
                                 2503, 1593, 2, 0, 16, 0, 3860, 28908,
                                 6, 2, 15, 49, 6246, 1946, 23, 105, 7996, 196, 0,
                                 2, 55, 457, 5, 3, 924, 7268, 16, 48, 4, 0, 12, 116, 2628, 1468};
    // vector<int> deliciousness = {1, 1, 1, 3, 3, 3, 7};
    int ans = countPairs(deliciousness);
    cout << ans << endl;

    return 0;
}