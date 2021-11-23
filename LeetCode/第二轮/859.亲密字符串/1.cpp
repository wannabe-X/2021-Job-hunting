/*
 * @Description: 859. 亲密字符串
 * @Author: Mr. Lee
 * @Date: 2021-11-23 09:28:33
 * @LastEditTime: 2021-11-23 10:09:16
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool buddyStrings(string s, string goal)
{
    if (s.size() != goal.size())
        return false;
    if (s == goal)
    {
        vector<int> count(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            count[s[i] - 'a']++;
            if (count[s[i] - 'a'] > 1)
                return true;
        }
        return false;
    }
    else
    {
        int a = -1, b = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != goal[i])
            {
                if (a == -1)
                    a = i;
                else if (b == -1)
                    b = i;
                else
                    return false;
            }
        }

        return b != -1 && s[a] == goal[b] && s[b] == goal[a];
    }
}

int main(int argc, char *argv[])
{
    string s = "ab", goal = "ba";
    bool ans = buddyStrings(s, goal);
    cout << boolalpha << ans << endl;

    return 0;
}