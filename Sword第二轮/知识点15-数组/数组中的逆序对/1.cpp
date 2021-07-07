/*
 * @Description: 数组中的逆序对。超出内存使用限制
 * @Author: Mr. Lee
 * @Date: 2021-07-01 17:25:19
 * @LastEditTime: 2021-07-07 17:54:27
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

int InversePairs(vector<int> data)
{
    int res = 0, n = data.size();
    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (data[i] > data[j])
            {
                res++;
                res %= 1000000007;
            }
        }
    }

    return res;
}

int main()
{
    vector<int> nums = {1, 2, 3, 5, 4};
    int ans = InversePairs(nums);
    cout << ans << endl;

    return 0;
}
