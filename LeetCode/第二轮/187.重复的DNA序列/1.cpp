/*
 * @Description: 187. 重复的DNA序列
 * @Author: Mr. Lee
 * @Date: 2021-L-08 09:36:50
 * @LastEditTime: 2021-10-08 09:56:42
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> findRepeatedDnaSequences(string s)
{
    vector<string> res;

    unordered_map<string, int> myMap;
    int L = 10, n = s.size();
    for (int i = 0; i <= n - L; i++)
    {
        myMap[s.substr(i, L)]++;
        if (myMap[s.substr(i, L)] == 2)
            res.push_back(s.substr(i, L));
    }

    return res;
}

int main(void)
{
    string s = "A";
    vector<string> ans = findRepeatedDnaSequences(s);
    for (auto str : ans)
        cout << str << endl;

    return 0;
}