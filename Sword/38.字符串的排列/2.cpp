#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 参考解法 主要是针对重复的元素做处理
vector<string> ret;

void dfs(string &path, string &s, vector<bool> &visited)
{
    if (path.size() == s.size())
    {
        ret.push_back(path);
        return;
    }

    for (int i = 0; i < s.size(); i++)
    {
        // 当前位置已访问，已在当前path中
        if (visited[i])
            continue;
        // 前一个位置的字符与当前位置相同，且前一个位置字符已经访问过
        if (i > 0 && s[i - 1] == s[i] && visited[i - 1])
            continue;

        visited[i] = true;
        path.push_back(s[i]);

        dfs(path, s, visited);
        path.pop_back();
        visited[i] = false;
    }
}

vector<string> permutation(string s)
{
    // DFS
    vector<bool> visited(s.size(), false);
    string path;
    // 排序后使得相同元素前后排列方便去重
    sort(s.begin(), s.end());
    dfs(path, s, visited);
    return ret;
}

int main(void)
{
    string s = "acc";
    vector<string> ans = permutation(s);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}