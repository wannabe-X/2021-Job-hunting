#include <iostream>
#include <vector>
using namespace std;

bool inArea(vector<vector<int>> &image, int x, int y)
{
    return x >= 0 && x < image.size() && y >= 0 && y < image[0].size();
}

int fill(vector<vector<int>> &image, int x, int y, int origColor, int newColor, vector<vector<bool>> &visited)
{
    if (!inArea(image, x, y))
        return 1;

    if (visited[x][y])
        return 1;

    if (image[x][y] != origColor)
        return 0;

    visited[x][y] = true;

    int surround = fill(image, x - 1, y, origColor, newColor, visited) +
                   fill(image, x + 1, y, origColor, newColor, visited) +
                   fill(image, x, y - 1, origColor, newColor, visited) +
                   fill(image, x, y + 1, origColor, newColor, visited);

    if (surround < 4)
        image[x][y] = newColor;

    return 1;
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor, vector<vector<bool>> &visited)
{
    int origColor = image[sr][sc];

    fill(image, sr, sc, origColor, newColor, visited);
    return image;
}

int main(void)
{
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1, sc = 1, newColor = 2;
    vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
    vector<vector<int>> ans = floodFill(image, sr, sc, newColor, visited);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << endl;
    }
}