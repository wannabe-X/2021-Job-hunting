/*
 * @Description: 剑指 Offer II 086. 分割回文子字符串
 * @Author: Mr. Lee
 * @Date: 2021-09-08 17:01:29
 * @LastEditTime: 2021-09-09 00:07:13
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> res;
vector<string> subStr;

bool isPalindrome(string str)
{
    int i = 0, j = str.size() - 1;
    while (i < j)
    {
        if (str[i++] != str[j--])
            return false;
    }

    return true;
}

void boardtrack(string s, int idx)
{
    if (idx == s.size())
    {
        res.push_back(subStr);
        return;
    }

    for (int i = idx; i < s.size(); i++)
    {
        string str = s.substr(idx, i - idx + 1);
        if (isPalindrome(str))
        {
            subStr.push_back(str);
            boardtrack(s, i + 1);
            subStr.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    boardtrack(s, 0);
    return res;
}

int main(void)
{
    string s = "google";
    vector<vector<string>> ans = partition(s);
    for (auto &x : ans)
    {
        for (auto &y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}