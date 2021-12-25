/*
 * @Description: 1078. Bigram 分词
 * @Author: Mr. Lee
 * @Date: 2021-12-26 00:07:45
 * @LastEditTime: 2021-12-26 00:39:26
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> findOcurrences(string text, string first, string second)
{
    vector<string> res, lists;

    string tmp;
    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] != ' ')
            tmp += text[i];
        else
        {
            lists.push_back(tmp);
            tmp.clear();
        }
    }

    if (!tmp.empty())
        lists.push_back(tmp);

    for (int i = 1; i < lists.size(); i++)
    {
        if (lists[i - 1] == first && lists[i] == second && (i + 1 < lists.size()))
            res.push_back(lists[i + 1]);
    }

    return res;
}

int main(int argc, char *argv[])
{
    string text = "alice is a good girl she is a good student", first = "a", second = "good";
    vector<string> ans = findOcurrences(text, first, second);
    for (auto str : ans)
        cout << str << " ";

    return 0;
}