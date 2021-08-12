/*
 * @Description: 剑指OfferII004.只出现一次的数字 
 * @Author: Mr. Lee
 * @Date: 2021-08-12 15:14:07
 * @LastEditTime: 2021-08-12 15:39:34
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>

using namespace std;

int singleNumber(vector<int> &nums)
{
    int res = 0;
    for (int i = 0; i < 32; i++)
    {
        int count = 0;
        for (int num : nums)
        {
            count += ((num >> i) & 1);
        }
        res += ((count % 3) << i);
    }

    return res;
}

int main()
{
    vector<int> nums = {2, 2, 3, 2};
    int ans = singleNumber(nums);
    cout << ans << endl;

    return 0;
}
