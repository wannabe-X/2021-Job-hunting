/*
 * @Description: 553. 最优除法
 * @Author: Mr. Lee
 * @Date: 2022-02-27 23:16:03
 * @LastEditTime: 2022-02-27 23:24:24
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    贪心算法:使分母尽可能的小,越除越小
*/
string optimalDivision(vector<int> &nums)
{
    int n = nums.size();
    string res;
    if (n > 2)
    {
        res = to_string(nums[0]) + '/' + '(';
        for (int i = 1; i < n - 1; i++)
            res += to_string(nums[i]) + '/';
        res += to_string(nums[n - 1]) + ')';
    }
    else if (n == 2)
        res = to_string(nums[0]) + '/' + to_string(nums[1]);
    else
    {
        res = to_string(nums[0]);
    }

    return res;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1000, 100, 10, 2};
    string ans = optimalDivision(nums);
    cout << ans << endl;

    return 0;
}