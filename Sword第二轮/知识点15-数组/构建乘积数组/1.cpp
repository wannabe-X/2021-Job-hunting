/*
 * @Description: 构建乘积数组
 * @Author: Mr. Lee
 * @Date: 2021-07-01 17:11:14
 * @LastEditTime: 2021-07-01 17:22:20
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> multiply(const vector<int> &A)
{
    int p = 1;
    vector<int> res(A.size(), 1);
    for (int i = 0; i < A.size(); i++)
    {
        res[i] *= p;
        p *= A[i];
    }

    p = 1;
    for (int i = A.size() - 1; i > -1; i--)
    {
        res[i] *= p;
        p *= A[i];
    }

    return res;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> ans = multiply(nums);
    for (int num : ans)
        cout << num << endl;

    return 0;
}
