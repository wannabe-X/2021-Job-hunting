#include <iostream>
#include <vector>

using namespace std;

// 利用回溯算法
vector<vector<int>> res;

void backtrack(int n, int k, int start, vector<int> &track)
{
    if (k == track.size())
    {
        res.push_back(track);
        return;
    }

    for (int i = start; i <= n; i++)
    {
        track.push_back(i);
        backtrack(n, k, i + 1, track);
        track.pop_back();
    }
}

vector<vector<int>> combine(int n, int k)
{
    if (n == 0 || n == 1)
        return res;
    vector<int> track;
    backtrack(n, k, 1, track);
    return res;
}

int main(void)
{
    int n = 4, k = 2;
    vector<vector<int>> ans = combine(n, k);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << endl;
        cout << endl;
    }
}