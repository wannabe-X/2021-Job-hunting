/*
 * @Description: 1711. 大餐计数。暴力破解超时
 * @Author: Mr. Lee
 * @Date: 2021-07-07 00:04:00
 * @LastEditTime: 2021-07-07 01:04:23
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool isN(int n)
{
    return (n & (n - 1)) == 0;
}

int countPairs(vector<int> &deliciousness)
{
    int n = deliciousness.size();
    unordered_map<int, bool> seen;

    int count = 0;
    long long k = 10e9 + 7;

    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            int tmp = deliciousness[i] + deliciousness[j];
            if (tmp < 1)
                continue;

            if (!seen.count(tmp))
            {
                seen[tmp] = ((tmp & (tmp - 1)) == 0);
            }

            if (seen[tmp])
                count++;
        }
    }

    return count;
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