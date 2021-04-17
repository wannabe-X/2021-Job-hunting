#include <iostream>
#include <vector>

using namespace std;

// 从外到里的遍历主要就是
// 依次从左到右、从上到下、从右到左、从下到上 四种遍历方式的循环
// 每遍历依次，相应的操作数减一 也就是--操作
// 另外注意边界条件
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    if (matrix.size() == 0)
        return {};
    int left = 0, right = matrix[0].size() - 1, top = 0, bottom = matrix.size() - 1, x = 0;
    vector<int> res((right + 1) * (bottom + 1));

    while (true)
    {
        // 从左到右
        for (int i = left; i <= right; i++)
            res[x++] = matrix[top][i];
        if (++top > bottom)
            break;
        // 从上到下
        for (int i = top; i <= bottom; i++)
            res[x++] = matrix[i][right];
        if (--right < left)
            break;
        // 从右到左
        for (int i = right; i >= left; i--)
            res[x++] = matrix[bottom][i];
        if (--bottom < top)
            break;
        // 从下到上
        for (int i = bottom; i >= top; i--)
            res[x++] = matrix[i][left];
        if (++left > right)
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