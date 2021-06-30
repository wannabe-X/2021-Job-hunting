/*
 * @Description: 调整数组顺序使奇数位于偶数前面
 * @Author: Mr. Lee
 * @Date: 2021-06-30 16:23:52
 * @LastEditTime: 2021-06-30 16:36:23
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> reOrderArray(vector<int> &array)
{
    vector<int> odd, even;
    for (int num : array)
    {
        if (num & 1)
            odd.push_back(num);
        else
            even.push_back(num);
    }

    odd.insert(odd.end(), even.begin(), even.end());
    
    return odd;
}

int main()
{
    vector<int> array = {1, 2, 3, 4};
    vector<int> ans = reOrderArray(array);
    for (int num : ans)
    {
        cout << num << " " << endl;
    }

    return 0;
}