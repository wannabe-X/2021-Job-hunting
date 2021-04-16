#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> res;

// 参考解法 考虑大数的情况
void dfs(int n, int idx, string path)
{
    if (idx == n)
    {
        int val = stoi(path);
        if (val != 0)
        {
            res.push_back(val);
        }
        return;
    }

    for (int i = 0; i < 10; i++)
    {
        path[idx] = i + '0';
        dfs(n, idx + 1, path);
    }
}

vector<int> printNumbers(int n)
{
    string path(n, '0');
    dfs(n, 0, path);
    return res;
}

int main(void)
{
    int n = 3;
    vector<int> ans = printNumbers(n);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}