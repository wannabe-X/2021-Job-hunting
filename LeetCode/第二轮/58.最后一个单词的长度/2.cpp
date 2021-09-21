/*
 * @Description: 58. 最后一个单词的长度
 * @Author: Mr. Lee
 * @Date: 2021-09-21 23:36:19
 * @LastEditTime: 2021-09-21 23:44:12
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lengthOfLastWord(string s)
{
    int j = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
            j = i;
    }

    for (int k = j; k >= 0; k--)
    {
        if (s[k] == ' ')
            return j - k;
    }

    return j + 1;
}

int main(void)
{
    string s = "luffy is still joyboy";
    int ans = lengthOfLastWord(s);
    cout << ans << endl;

    return 0;
}