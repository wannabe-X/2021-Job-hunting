#include <iostream>
#include <vector>

using namespace std;

bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
{
    if (matrix.size() < 1)
        return false;
    int i = 0, k = matrix[0].size();
    while (i < matrix.size())
    {
        for (int j = 0; j < k; j++)
        {
            if (matrix[i][j] == target)
                return true;
            if (matrix[i][j] > target)
            {
                k = j;
                break;
            }
        }
        i++;
    }
    return false;
}

int main(void)
{
    vector<vector<int>> matrix = {};
    int target = 0;
    bool ans = findNumberIn2DArray(matrix, target);
    cout << boolalpha;
    cout << ans << endl;
    return 0;
}