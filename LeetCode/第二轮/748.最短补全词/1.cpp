/*
 * @Description: 748. 最短补全词
 * @Author: Mr. Lee
 * @Date: 2021-12-10 00:13:39
 * @LastEditTime: 2021-12-10 00:38:31
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int> word1, vector<int> word2)
{
    for (int i = 0; i < 26; i++)
    {
        if (word1[i] > word2[i])
            return false;
    }
    return true;
}

string shortestCompletingWord(string licensePlate, vector<string> &words)
{
    vector<int> v(26, 0);
    string res;
    for (char c : licensePlate)
        if (isalpha(c))
            v[tolower(c) - 'a']++;

    int length = INT_MAX;
    for (auto str : words)
    {
        vector<int> tmp(26, 0);
        for (char c : str)
            tmp[c - 'a']++;

        if (comp(v, tmp) && str.size() < length)
        {
            res = str;
            length = str.size();
        }
    }

    return res;
}

int main(int argc, char *argv[])
{
    string licensePlate = "1s3 PSt";
    vector<string> words = {"step", "steps", "stripe", "stepple"};
    string ans = shortestCompletingWord(licensePlate, words);
    cout << ans << endl;

    return 0;
}