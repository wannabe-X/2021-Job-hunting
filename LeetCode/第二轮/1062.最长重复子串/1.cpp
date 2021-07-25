/*
 * @Description: 1062.最长重复子串
 * @Author: Mr. Lee
 * @Date: 2021-07-24 22:22:49
 * @LastEditTime: 2021-07-24 23:07:27
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool chechRepeat(string &s, int k)
{
    // 检查长度为k的字符串是否有重复
    unordered_set<string> mySet;
    for (int i = 0; i <= s.size() - k; i++)
    {
        string tmp = s.substr(i, k);
        if (mySet.count(tmp))
            return true;
        else
            mySet.insert(move(tmp));
    }

    return false;
}

int longestRepeatingSubstring(string s)
{
    // 此时，是为了找到最小重复子串的长度，所以长度范围是从1到s.size()
    int left = 1, right = s.size();
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (chechRepeat(s, mid))
        {
            // 若是有长度为mid的子串重复，继续查找看mid+1的子串是否有重复
            left = mid + 1;
        }
        else
        {
            // right会一步步逼近于left，最终退出循环
            right = mid;
        }
    }

    return left - 1;
}

int main()
{
    string s = "aaaaa";
    int ans = longestRepeatingSubstring(s);
    cout << ans << endl;

    return 0;
}
