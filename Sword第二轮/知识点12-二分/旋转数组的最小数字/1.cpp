/*
 * @Description: 旋转数组的最小数字。直接查找最小的值即可
 * @Author: Mr. Lee
 * @Date: 2021-06-29 21:53:20
 * @LastEditTime: 2021-06-29 22:09:13
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

int minNumberInRotateArray(vector<int> rotateArray)
{
    if (rotateArray.size() == 0)
    {
        return 0;
    }

    int res = INT_MAX;
    for (int i = 0; i < rotateArray.size(); i++)
    {
        res = min(res, rotateArray[i]);
    }

    return res;
}

int main()
{
    vector<int> rotateArray = {3, 4, 5, 1, 2};
    int ans = minNumberInRotateArray(rotateArray);
    cout << ans << endl;

    return 0;
}
