#include <iostream>
#include <vector>

using namespace std;

// 参考代码
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    if (matrix.size() == 0)
        return {};
    int l = 0, r = matrix[0].size() - 1, t = 0, b = matrix.size() - 1, x = 0;
    vector<int> res((b + 1) * (r + 1));
    while (true)
    {
        for (int i = l; i <= r; i++)
            res[x++] = matrix[t][i]; // left to right.
        if (++t > b)
            break;

        for (int i = t; i <= b; i++)
            res[x++] = matrix[i][r]; // top to bottom.
        if (l > --r)
            break;

        for (int i = r; i >= l; i--)
            res[x++] = matrix[b][i]; // right to left.
        if (t > --b)
            break;

        for (int i = b; i >= t; i--)
            res[x++] = matrix[i][l]; // bottom to top.
        if (++l > r)
            break;
    }
    return res;
}

int main(void)
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> ans = spiralOrder(matrix);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    cout << endl;
}