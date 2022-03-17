/*
 * @Description: 720. 词典中最长的单词
 * @Author: Mr. Lee
 * @Date: 2022-03-17 21:00:53
 * @LastEditTime: 2022-03-17 21:37:59
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

string longestWord(vector<string> &words)
{
    sort(words.begin(), words.end(), [](string &a, string &b)
         { return a.size() != b.size() ? a.size() < b.size() : a > b; });
    unordered_set<string> st = {""};
    string res;

    for (const auto &word : words)
    {
        if (st.count(word.substr(0, word.size() - 1)))
        {
            st.insert(word);
            res = word;
        }
    }

    return res;
}

int main(int argc, char *argv[])
{
    vector<string> words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    string ans = longestWord(words);
    cout << ans << endl;

    return 0;
}