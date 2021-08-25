/*
 * @Description: 剑指 Offer II 033. 变位词组
 * @Author: Mr. Lee
 * @Date: 2021-08-21 00:18:30
 * @LastEditTime: 2021-08-21 00:39:06
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    if (strs.size() == 0)
        return "";
        
    unordered_map<string, int> m;
    int classification = 0;

    for (auto &str : strs)
    {
        string tmp = str;
        sort(tmp.begin(), tmp.end());
        if (!m.count(tmp))
            m[tmp] = classification++;
    }

    vector<vector<string>> res(m.size());

    for (auto &str : strs)
    {
        string tmp = str;
        sort(tmp.begin(), tmp.end());
        if (m.count(tmp))
        {
            res[m[tmp]].push_back(str);
        }
    }

    return res;
}

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = groupAnagrams(strs);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
