/*
 * @Description: 438. 找到字符串中所有字母异位词
 * @Author: Mr. Lee
 * @Date: 2021-11-28 00:30:12
 * @LastEditTime: 2021-11-28 00:52:58
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> findAnagrams(string s, string t)
{
    vector<int> res;
    unordered_map<char, int> windows, needs;

    for (char c : t)
        needs[c]++;

    int left = 0, right = 0, match = 0;

    while (right < s.size())
    {
        char c1 = s[right];
        if (needs.count(c1))
        {
            windows[c1]++;
            if (windows[c1] == needs[c1])
                match++;
        }
        right++;

        while (match == needs.size())
        {
            if (t.size() == right - left)
                res.push_back(left);
            char c2 = s[left];
            if (needs.count(c2))
            {
                windows[c2]--;
                if (windows[c2] < needs[c2])
                    match--;
            }
            left++;
        }
    }

    return res;
}

int main(int argc, char *argv[])
{
    string s = "cbaebabacd", p = "abc";
    vector<int> ans = findAnagrams(s, p);
    for (int num : ans)
        cout << num << " ";
    cout << endl;

    return 0;
}