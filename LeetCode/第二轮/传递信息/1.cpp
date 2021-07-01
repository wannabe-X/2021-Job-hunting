/*
 * @Description: 传递信息
 * @Author: Mr. Lee
 * @Date: 2021-07-01 00:29:41
 * @LastEditTime: 2021-07-01 00:52:02
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;
vector<int> transtatus(vector<vector<int>> &relation, int status)
{
    vector<int> trans;
    for (int i = 0; i < relation.size(); i++)
    {
        if (relation[i][0] == status)
            trans.push_back(relation[i][1]);
    }

    return trans;
}

int numWays(int n, vector<vector<int>> &relation, int k)
{
    int target = n - 1;
    int count = 0;

    queue<pair<int, int>> q;
    q.emplace(0, 0);
    unordered_set<int> seen = {0};

    while (!q.empty())
    {
        int curstatus = q.front().first, step = q.front().second;
        vector<int> nextstatus = transtatus(relation, curstatus);
        q.pop();

        for (int nxtstatus : nextstatus)
        {
            if (!seen.count(nxtstatus))
            {
                cout << nxtstatus << endl;
                if (nxtstatus == target && (step + 1) == k)
                    count++;
                q.emplace(nxtstatus, step + 1);
                seen.insert(move(nxtstatus));
            }
        }
    }

    return count;
}

int main()
{
    int n = 5, k = 3;
    vector<vector<int>> relation = {{0, 2}, {2, 1}, {3, 4}, {2, 3}, {1, 4}, {2, 0}, {0, 4}};
    int ans = numWays(n, relation, k);
    cout << ans << endl;
    return 0;
}
