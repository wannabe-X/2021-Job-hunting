#include <iostream>
#include <vector>
using namespace std;

bool inArea(vector<vector<int>> &image, int x, int y)
{
    return x >= 0 && x < image.size() && y >= 0 && y < image[0].size();
}

void fill(vector<vector<int>> &image, int x, int y, int origColor, int newColor)
{
    if (!inArea(image, x, y) || image[x][y] != origColor || image[x][y] == -1)
        return;

    image[x][y] = -1;

    fill(image, x - 1, y, origColor, newColor);
    fill(image, x + 1, y, origColor, newColor);
    fill(image, x, y - 1, origColor, newColor);
    fill(image, x, y + 1, origColor, newColor);

    image[x][y] = newColor;
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int origColor = image[sr][sc];
    fill(image, sr, sc, origColor, newColor);
    return image;
}

int main(void)
{
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1, sc = 1, newColor = 2;
    vector<vector<int>> ans = floodFill(image, sr, sc, newColor);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << endl;
    }
}