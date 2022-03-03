/*
 * @Description: 564. 寻找最近的回文数
 * @Author: Mr. Lee
 * @Date: 2022-03-02 22:35:05
 * @LastEditTime: 2022-03-02 22:54:14
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

vector<long> getCandidates(string n)
{
    int len = n.size();
    vector<long> candidates = {long(pow(10, len - 1) - 1),
                               long(pow(10, len) + 1)};
    long num = stol(n.substr(0, (len + 1) / 2)); // 取出前半部分
    for (int i : {num, num - 1, num + 1})
    {
        string prefix = to_string(i);
        string candidate = prefix + string(prefix.rbegin() + (len & 1), prefix.rend());
        candidates.push_back(stol(candidate));
    }
    return candidates;
}

string nearestPalindromic(string n)
{
    long selfNum = stol(n), ans = -1;
    vector<long> candidates = getCandidates(n);
    for (long candidate : candidates)
    {
        if (candidate != selfNum)
        {
            if (ans == -1 || abs(candidate - selfNum) < abs(ans - selfNum) || abs(candidate - selfNum) == abs(ans - selfNum) && candidate < ans)
                ans = candidate;
        }
    }

    return to_string(ans);
}

int main(int argc, char *argv[])
{
    string n = "123";
    string ans = nearestPalindromic(n);
    cout << ans << endl;

    return 0;
}