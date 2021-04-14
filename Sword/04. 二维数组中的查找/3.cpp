#include <iostream>
#include <vector>

using namespace std;

// 参考代码
bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
{
    int i = matrix.size() - 1, j = 0;
    while (i > -1 && j < matrix[0].size())
    {
        if (matrix[i][j] > target)
            i--;
        else if (matrix[i][j] < target)
            j++;
        else
            return true;
    }
    return false;
}

int main(void)
{
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};
    int target = 5;
    bool ans = findNumberIn2DArray(matrix, target);
    cout << boolalpha;
    cout << ans << endl;
    return 0;
}