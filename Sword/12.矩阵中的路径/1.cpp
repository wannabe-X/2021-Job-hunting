#include <iostream>
#include <vector>

using namespace std;

// 回溯算法
bool boardtrack(int x, int y, int z, vector<vector<char>> &board, string word)
{
    if (x < 0 || y < 0 || x >= board.size() ||
        y >= board[0].size() || board[x][y] != word[z])
        return false;

    if (z == word.size() - 1)
        return true;

    board[x][y] = '/'; // 防止走回头路

    // 做选择
    bool res = boardtrack(x + 1, y, z + 1, board, word) || boardtrack(x - 1, y, z + 1, board, word) || boardtrack(x, y + 1, z + 1, board, word) || boardtrack(x, y - 1, z + 1, board, word);

    board[x][y] = word[z]; // 撤销选择

    return res;
}

bool exist(vector<vector<char>> &board, string word)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (boardtrack(i, j, 0, board, word)) // 回溯算法board[i][j]为起点能否找到word
                return true;
        }
    }
    return false;
}

int main(void)
{
    // vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    // string word = "ABCCED";

    vector<vector<char>> board = {{'a', 'b'}, {'c', 'd'}};
    string word = "abcd";
    bool ans = exist(board, word);
    cout << boolalpha;
    cout << ans << endl;
    return 0;
}