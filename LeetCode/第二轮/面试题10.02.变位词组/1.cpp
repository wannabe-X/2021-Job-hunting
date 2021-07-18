/*
 * @Description: 面试题 10.02. 变位词组
 * @Author: Mr. Lee
 * @Date: 2021-07-18 00:29:53
 * @LastEditTime: 2021-07-18 01:07:59
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, int> m;
    int cla = 0;
    
    // 分类 
    for (string &s : strs)
    {
        sort(s.begin(), s.end());
        if (!m.count(s))
            m[s] = cla++;
    }

    vector<vector<string>> res(m.size());
    // 对每一个词进行分类，归到正确的类别中
    for (string &s : strs)
    {
        string tmp = s;
        sort(tmp.begin(), tmp.end());
        res[m[tmp]].push_back(s);
    }

    return res;
}

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = groupAnagrams(strs);
    for (auto &s : ans)
    {
        for (auto &ss : s)
            cout << ss << " ";
    }

    cout << endl;

    return 0;
}
