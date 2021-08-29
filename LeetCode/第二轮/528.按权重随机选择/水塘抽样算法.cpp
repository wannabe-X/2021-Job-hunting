/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-08-30 00:50:39
 * @LastEditTime: 2021-08-30 01:08:19
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <time.h>

using namespace std;

vector<int> ReservoirSampling(vector<int> &nums, int k)
{
    // results.size(): k
    // nums.size(): N
    int N = nums.size();
    vector<int> results(k);
    srand(time(0));

    for (int i = 0; i < k; ++i)
    {
        results[i] = nums[i];
    }

    for (int i = k; i < N; ++i)
    {
        int random = rand() % i;
        cout << random << endl;
        if (random < k)
        {
            results[random] = nums[i];
        }
    }

    return results;
}

int main(void)
{
    vector<int> nums;
    int k = 5;
    for (int i = 1; i < 11; i++)
        nums.push_back(i);

    vector<int> ans = ReservoirSampling(nums, k);
    for (int i = 0; i < k; i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}