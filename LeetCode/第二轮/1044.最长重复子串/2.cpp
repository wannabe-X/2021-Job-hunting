/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-08-10 13:16:39
 * @LastEditTime: 2021-08-10 13:30:18
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <unordered_set>
#include <math.h>

using namespace std;

int search(int strlen, int a, long mod, vector<int> &nums)
{
    long h = 0, carry = 1;

    for (int i = 0; i < strlen; i++)
    {
        h = (h * a + nums[i]) % mod;
        carry = (carry * a) % mod;
    }

    unordered_set<long> seen;
    seen.insert(h);

    for (int i = 1; i < nums.size() - strlen + 1; i++)
    {
        h = (h * a % mod - nums[i - 1] * carry % mod) % mod;
        h = (h + nums[i - 1 + strlen]) % mod;
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
        nums[i] = s[i] - 'a';

    int a = 26;
    long mod = long(pow(2, 32));

    int left = 1, right = n;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (search(mid, a, mod, nums) != -1)
            left = mid + 1;
        else
            right = mid;
    }

    int start = search(left - 1, a, mod, nums);

    return start != -1 ? s.substr(start, left - 1) : "";
}

int main(void)
{
    string s = "banana";
    string ans = longestDupSubstring(s);
    cout << ans << endl;

    return 0;
}