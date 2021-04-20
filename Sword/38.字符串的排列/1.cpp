#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> res;

// 回溯算法
void backtrack(string &s, string &temp, vector<bool> &used)
{
    if (temp.size() == s.size())
    {
        res.push_back(temp);
        return;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (used[i])
            continue;

        temp.push_back(s[i]);
        used[i] = true;
        backtrack(s, temp, used);
        temp.pop_back();
        used[i] = false;
    }
}

vector<string> permutation(string s)
{
    string temp;
    vector<bool> used(s.size(), false);
    // sort(s.begin(), s.end());
    backtrack(s, temp, used);
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    return res;
}

int main(void)
{
    string s = "ccc";
    vector<string> ans = permutation(s);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}