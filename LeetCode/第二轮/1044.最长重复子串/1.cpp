/*
 * @Description: 1044. 最长重复子串
 * @Author: Mr. Lee
 * @Date: 2021-08-09 16:34:21
 * @LastEditTime: 2021-08-09 23:10:38
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <math.h>

using namespace std;

int search(int l, int a, long modules, vector<int> &nums)
{
    long h = 0, carry = 1;
    for (int i = 0; i < l; i++)
    {
        h = (h * a + nums[i]) % modules;
        carry = (carry * a) % modules;
    }

    unordered_set<long> seen;
    seen.insert(h);

    for (int i = 1; i < nums.size() - l + 1; i++)
    {
        h = (h * a % modules - nums[i - 1] * carry % modules) % modules;
        h = (h + nums[i + l - 1]) % modules;
        if (seen.count(h))
            return i;
        seen.insert(h);
    }

    return -1;
}

string longestDupSubstring(string s)
{
    int n = s.size();
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        nums[i] = s[i] - 'a';
    }

    int a = 26;
    long modules = (long)pow(2, 32);
    int left = 1, right = n;

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (search(mid, a, modules, nums) != -1)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    int start = search(left - 1, a, modules, nums);

    return start != -1 ? s.substr(start, left - 1) : "";
}

int main()
{
    string s = "banana";
    string ans = longestDupSubstring(s);
    cout << ans << endl;

    return 0;
}
