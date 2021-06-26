/*
 * @Description: 773. 滑动谜题
 * @Author: Mr. Lee
 * @Date: 2021-06-26 09:28:12
 * @LastEditTime: 2021-06-26 17:41:33
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

vector<vector<int>> neighbors = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};

inline vector<string> getNextStatus(string &status)
{
    vector<string> ret;

    int zerolocation = status.find('0');

    for (int zeroswap : neighbors[zerolocation])
    {
        swap(status[zerolocation], status[zeroswap]);
        ret.push_back(status);
        swap(status[zerolocation], status[zeroswap]);
    }

    return ret;
}

int slidingPuzzle(vector<vector<int>> &board)
{
    string src = "000000", dst = "123450";
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
            src[i * 3 + j] = board[i][j] + '0';
    }

    if (src == dst)
        return 0;

    queue<pair<string, int>> q;
    unordered_set<string> seen = {src};
    q.emplace(src, 0);

    while (!q.empty())
    {
        string status = q.front().first;
        int step = q.front().second;
        q.pop();

        vector<string> tmpstatus = getNextStatus(status);

        for (auto &&nextstatus : tmpstatus)
        {
            if (!seen.count(nextstatus))
            {
                if (nextstatus == dst)
                {
                    return step + 1;
                }
                q.emplace(nextstatus, step + 1);
                seen.insert(move(nextstatus));
            }
        }
    }

    return -1;
}

int main()
{
    // 测试用例
    vector<vector<int>> board = {{1, 2, 3}, {5, 4, 0}};
    int ans = slidingPuzzle(board);
    cout << ans << endl;
    return 0;
}