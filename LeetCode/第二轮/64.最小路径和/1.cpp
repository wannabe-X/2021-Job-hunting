#include <iostream>
#include <vector>

using namespace std;

int minPathSum(vector<vector<int>> &grid)
{
    int r = grid.size(), l = grid[0].size();
    int tmp = 0;
    vector<vector<int>> res(r, vector<int>(l, 0));

    for (int i = 0; i < r; i++)
    {
        tmp += grid[i][0];
        res[i][0] = tmp;
    }

    tmp = 0;
    for (int i = 0; i < l; i++)
    {
        tmp += grid[0][i];
        res[0][i] = tmp;
    }

    for (int i = 1; i < r; i++)
    {
        for (int j = 1; j < l; j++)
        {
            res[i][j] = min(res[i][j - 1], res[i - 1][j]) + grid[i][j];
        }
    }
    return res[r - 1][l - 1];
}

int main()
{

    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int ans = minPathSum(grid);
    cout << ans << endl;
    return 0;
}