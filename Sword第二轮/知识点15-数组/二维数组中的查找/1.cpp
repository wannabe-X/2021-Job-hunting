/*
 * @Description: 二维数组中的查找
 * @Author: Mr. Lee
 * @Date: 2021-06-30 00:02:06
 * @LastEditTime: 2021-06-30 00:07:23
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

bool Find(int target, vector<vector<int>> array)
{
    for (int i = 0; i < array.size(); i++)
    {
        for (int j = 0; j < array[0].size(); j++)
        {
            if (array[i][j] > target)
                continue;
            else if (array[i][j] == target)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> array = {
        {1, 2, 8, 9},
        {2, 4, 9, 12},
        {4, 7, 10, 13},
        {6, 8, 11, 15}};
    int target = 7;
    bool ans = Find(target, array);
    cout << boolalpha << ans << endl;

    return 0;
}