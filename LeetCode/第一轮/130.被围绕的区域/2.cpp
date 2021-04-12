#include <iostream>
#include <vector>

using namespace std;

//先用 for 循环遍历棋盘的四边，
// 用 DFS 算法把那些与边界相连的 O 换成一个特殊字符，比如 #；然后再遍历整个棋盘，
// 把剩下的 O 换成 X，把 # 恢复成 O。时间复杂度 O(MN)

int n, m;

void dfs(vector<vector<char>> &board, int x, int y)
{
    // 非边界'O'条件 返回
    if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] != 'O')
    {
        return;
    }

    // 是边界'O' 将边界的'O'替换成'A'
    board[x][y] = 'A';

    // 以(x,y)为坐标的元素都递归检查一下是否为边界'O'
    dfs(board, x - 1, y); // 上
    dfs(board, x + 1, y); // 下
    dfs(board, x, y - 1); // 左
    dfs(board, x, y + 1); // 右
}

void solve(vector<vector<char>> &board)
{
    n = board.size();

    if (n == 0)
    {
        return;
    }

    m = board[0].size();

    // 第一列和最后一列
    for (int i = 0; i < n; i++)
    {
        dfs(board, i, 0);
        dfs(board, i, m - 1);
    }

    // 第一行和最后一行
    for (int i = 1; i < m - 1; i++)
    {
        dfs(board, 0, i);
        dfs(board, n - 1, i);
    }

    // 边界的'A'用'O'还原，非边界的'O'用'X'替换
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'A')
            {
                board[i][j] = 'O';
            }
            else if (board[i][j] == 'O')
            {
                board[i][j] = 'X';
            }
        }
    }
}

int main(void)
{
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
                                  {'X', 'O', 'O', 'X'},
                                  {'X', 'X', 'O', 'X'},
                                  {'X', 'O', 'X', 'X'}};
    solve(board);

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
            cout << board[i][j] << ' ';
        cout << endl;
    }
}