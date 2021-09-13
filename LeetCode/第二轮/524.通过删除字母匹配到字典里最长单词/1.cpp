/*
 * @Description: 524. 通过删除字母匹配到字典里最长单词
 * @Author: Mr. Lee
 * @Date: 2021-09-14 00:08:45
 * @LastEditTime: 2021-09-14 01:02:53
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstring>

using namespace std;

bool isContain(string str, string tmp)
{
    int j = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == tmp[j])
            j++;
    }

    return j == tmp.size();
}

string findLongestWord(string s, vector<string> &dictionary)
{
    string res;

    for (auto &word : dictionary)
    {

        if (isContain(s, word) && (word.size() >= res.size()))
        {
            if (res.size() == word.size() && res > word)
                res = word;
                
            if (res.size() < word.size())
            {
                res = word;
            }
        }
    }

    return res;
}

int main(void)
{
    string s = "abpcplea";
    vector<string> dictionary = {"a", "b", "c", "d"};
    string ans = findLongestWord(s, dictionary);
    cout << ans;

    return 0;
}