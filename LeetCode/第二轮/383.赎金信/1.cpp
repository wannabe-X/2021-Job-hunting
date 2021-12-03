/*
 * @Description:
 * @Author: Mr. Lee
 * @Date: 2021-12-04 00:23:11
 * @LastEditTime: 2021-12-04 00:44:36
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    unordered_map<char, int> mr, mm;
    for (char c : ransomNote)
        mr[c]++;
    for (char c : magazine)
        mm[c]++;
    for (auto it = mr.begin(); it != mr.end(); it++)
    {
        if (!(mm.count((*it).first) && (*it).second <= mm[(*it).first]))
            return false;
    }

    return true;
}

int main(int argc, char *argv[])
{
    string ransomNote = "aa";
    string magazine = "aab";
    bool ans = canConstruct(ransomNote, magazine);
    cout << boolalpha << ans << endl;

    return 0;
}