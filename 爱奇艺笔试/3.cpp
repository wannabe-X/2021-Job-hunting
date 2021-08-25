/*
 * @Description: 象棋问题
 * @Author: Mr. Lee
 * @Date: 2021-08-22 14:44:27
 * @LastEditTime: 2021-08-22 16:54:37
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

void boardtrack(vector<vector<string>> &res, vector<string> &bd, vector<int> &position, vector<int> &fg1, vector<int> &fg2, int location)
{
    // 返回条件
    if (location == position.size())
    {
        res.push_back(bd);
        return;
    }

    // 开始回溯
    for (int i = 0; i < position.size(); i++)
    {
        if (position[i] == 0)
        {
            continue;
        }

        int n = i - location;
        int m = i + location;

        n += (position.size() - 1);
        if (!fg1[n] || !fg2[m])
        {
            continue;
        }

        position[i] = 0;
        bd[location][i] = 'Q';
        fg1[n] = 0;
        fg2[m] = 0;

        // 向下递归
        boardtrack(res, bd, position, fg1, fg2, location + 1);
        // 返回后回溯
        position[i] = 1;
        bd[location][i] = '.';
        fg1[n] = 1;
        fg2[m] = 1;
    }
}

vector<vector<string>> Nqueens(int n)
{
    // if (n <= 3)
    //     return {};
    vector<vector<string>> res;
    vector<string> bd(n, string(n, '.'));
    vector<int> position(n, 1), fg1(2 * n - 1, 1), fg2(2 * n - 1, 1);
    // 使用回溯算法
    boardtrack(res, bd, position, fg1, fg2, 0);

    return res;
}

int main()
{
    // 测试用例
    int n;
    cin >> n;
    vector<vector<string>> ans = Nqueens(n);

    if (ans.size() <= 1)
    {
        cout << '[';
        for (int i = 0; i < ans.size(); i++)
        {
            cout << '[';
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j];
            }
            cout << ']';
        }
        cout << ']';
    }
    else if (ans.size() > 1)
    {
        cout << "[";

        for (int i = 0; i < ans.size() - 1; i++)
        {
            cout << "[";
            for (int j = 0; j < ans[i].size() - 1; j++)
            {
                cout << ans[i][j] << ", ";
            }
            cout << ans[i][ans[i].size() - 1];
            cout << "], ";
        }

        for (int i = ans.size() - 1; i < ans.size(); i++)
        {
            cout << "[";
            for (int j = 0; j < ans[i].size() - 1; j++)
            {
                cout << ans[i][j] << ", ";
            }
            cout << ans[i][ans[i].size() - 1];
            cout << "]";
        }

        cout << "]";

        cout << endl;
    }

    return 0;
}
