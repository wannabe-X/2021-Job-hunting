/*
 * @Description: 752.打开转盘锁
 * @Author: Mr. Lee
 * @Date: 2021-06-25 09:40:51
 * @LastEditTime: 2021-06-25 17:40:42
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

// 逆时针旋转
char num_prev(char x)
{
    return x == '0' ? '9' : x - 1;
}

// 顺时针旋转
char num_succ(char x)
{
    return x == '9' ? '0' : x + 1;
}

// 获得每个状态下一步的转移结果
vector<string> get(string &status)
{
    vector<string> ret;
    for (int i = 0; i < 4; i++)
    {
        char num = status[i];
        status[i] = num_prev(num);
        ret.push_back(status);
        status[i] = num_succ(num);
        ret.push_back(status);
        status[i] = num;
    }
    return ret;
}

int openLock(vector<string> &deadends, string target)
{
    if (target == "0000")
    {
        return 0;
    }

    unordered_set<string> dead(deadends.begin(), deadends.end());
    if (dead.count("0000"))
    {
        return -1;
    }

    queue<pair<string, int>> q;
    q.emplace("0000", 0);
    unordered_set<string> seen = {"0000"};

    while (!q.empty())
    {
        string status = q.front().first;
        int step = q.front().second;
        q.pop();

        vector<string> tmp_status = get(status);

        for (string next_status : tmp_status)
        {
            if (!seen.count(next_status) && !dead.count(next_status))
            {
                if (next_status == target)
                {
                    return step + 1;
                }
                q.emplace(next_status, step + 1);
                seen.insert(next_status);
            }
        }
    }

    return -1;
}

int main()
{
    // vector<string> deadends = {"0201", "0101", "0102", "1212", "2002"};
    // string target = "0202";
    // int ans = openLock(deadends, target);
    // cout << ans << endl;

    //
    int idx = 0, n;
    cin >> n;
    vector<string> deadends(n);
    string target;
    while (cin >> deadends[idx++] && idx < n)
        ;
    cin >> target;

    int ans = openLock(deadends, target);
    cout << ans << endl;

    return 0;
}
