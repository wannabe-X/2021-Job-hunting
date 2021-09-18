/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-17 19:37:35
 * @LastEditTime: 2021-09-17 20:56:44
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

string func(int tmp)
{
    string res;
    string s = to_string(tmp);
    vector<string> v;
    unordered_map<int, string> m;
    m[0] = '0', m[1] = '1', m[2] = "10", m[3] = "11", m[4] = "100", m[5] = "101", m[6] = "110", m[7] = "111", m[8] = "1000", m[9] = "1001";

    for (int i = s.size() - 1; i > -1; i--)
    {
        v.push_back(m[s[i] - '0']);
    }

    for (int i = 0; i < v.size(); i++)
        res = v[i] + res;

    reverse(res.begin(), res.end());
    int i = 0;
    for (; i < res.size() && res[i] == '0'; i++)
        ;
    res = res.substr(i);
    i = 0;
    string ans;
    for (; i < res.size() - 1; i++)
    {
        if (res[i] != res[i + 1])
            ans = res[i] + ans;
    }
    if (res[i] != ans.front())
        ans = res[i] + ans;
    return ans;
}

int main(void)
{
    int N, tmp;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        string ans = func(tmp);
        cout << ans << endl;
    }

    return 0;
}