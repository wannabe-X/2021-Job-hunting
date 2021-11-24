/*
 * @Description: 423. 从英文中重建数字
 * @Author: Mr. Lee
 * @Date: 2021-11-24 09:13:36
 * @LastEditTime: 2021-11-24 10:14:32
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string originalDigits(string s)
{
    vector<int> cnts(26, 0);
    vector<string> ss = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    vector<int> priority = {0, 8, 6, 3, 2, 7, 5, 9, 4, 1};
    for (char c : s)
        cnts[c - 'a']++;

    string res;
    for (int num : priority)
    {
        int k = INT_MAX;
        for (char c : ss[num])
            k = min(k, cnts[c - 'a']);
        for (char c : ss[num])
            cnts[c - 'a'] -= k;
        while (k-- > 0)
            res += to_string(num);
    }

    sort(res.begin(), res.end());
    return res;
}

int main(int argc, char *argv[])
{
    string s = "owoztneoer";
    string ans = originalDigits(s);
    cout << ans << endl;

    return 0;
}