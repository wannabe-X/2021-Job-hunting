#include <iostream>
#include <vector>

using namespace std;

class UF
{
private:
    int *parent;
    int *size;

public:
    UF(int n)
    {
        parent = new int(n);
        size = new int(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int Find(int x)
    {
        while (x != parent[x])
        {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void Union(int p, int q)
    {
        int rootP = Find(p);
        int rootQ = Find(q);

        if (rootP == rootQ)
            return;

        if (size[rootP] > size[rootQ])
        {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        else
        {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
    }

    bool Connected(int p, int q)
    {
        int rootP = Find(p);
        int rootQ = Find(q);
        return rootP == rootQ;
    }
};

void solve(vector<vector<char>> &board)
{
    if (board.size() == 0)
        return;

    int m = board.size();    // 行
    int n = board[0].size(); // 列
    int dummy = m * n;

    UF uf(dummy);

    for (int i = 0; i < m; i++)
    {
        if (board[i][0] == 'O')
            uf.Union(i * n, dummy);
        if (board[i][n] == 'O')
            uf.Union(i * n + n - 1, dummy);
    }

    for (int j = 0; j < n; j++)
    {
        if (board[0][j] == 'O')
            uf.Union(j, dummy);
        if (board[m - 1][j] == 'O')
            uf.Union((m - 1) * n + j, dummy);
    }

    vector<vector<int>> d = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    for (int i = 1; i < m - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            if (board[i][j] == 'O')
            {
                for (int k = 0; k < 4; k++)
                {
                    int x = i + d[k][0], y = j + d[k][1];
                    if (board[x][y] == 'O')
                        uf.Union(x * n + y, i * n + j);
                }
            }
        }
    }

    for (int i = 1; i < m - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            if (!uf.Connected(dummy, i * n + j))
                board[i][j] = 'X';
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