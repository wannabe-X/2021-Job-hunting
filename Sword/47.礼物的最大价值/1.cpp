#include <iostream>
#include <vector>

using namespace std;

int maxValue(vector<vector<int>> &grid)
{
    vector<vector<int>> res(grid.size(), vector<int>(grid[0].size(), 0));
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            int left = 0, up = 0;
            if (i > 0)
                up = res[i - 1][j];
            if (j > 0)
                left = res[i][j - 1];

            res[i][j] = max(left, up) + grid[i][j];
        }
    }

    int maxValue = res[grid.size() - 1][grid[0].size() - 1];

    return maxValue;
}

int main(void)
{
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}};
    int ans = maxValue(grid);
    cout << ans << endl;
    return 0;
}