/*
 * @Description: 500. 键盘行
 * @Author: Mr. Lee
 * @Date: 2021-10-31 22:35:27
 * @LastEditTime: 2021-10-31 23:04:24
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool check(string str)
{
    vector<string> keyboard = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
    unordered_map<char, int> m;
    for (int i = 0; i < keyboard.size(); i++)
        for (char c : keyboard[i])
            m[c] = i;

    int flag = m[tolower(str[0])];

    for (int i = 1; i < str.size() && flag == m[tolower(str[0])]; i++)
        flag = m[tolower(str[i])];

    return flag == m[tolower(str[0])];
}

vector<string> findWords(vector<string> &words)
{
    vector<string> res;
    for (string word : words)
    {
        cout << check(word) << endl;
        if (check(word))
            res.push_back(word);
    }

    return res;
}

int main(int argc, char **argv)
{
    vector<string> words = {"Dad"};
    vector<string> ans = findWords(words);
    for (string str : ans)
        cout << str << " ";
    cout << endl;

    return 0;
}