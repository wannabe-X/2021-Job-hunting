/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-07-26 22:35:53
 * @LastEditTime: 2021-07-26 22:39:43
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>

using namespace std;

int Add(vector<int> &a)
{
    int sum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];
    }

    return sum;
}

int main()
{
    int len;
    cin >> len;
    while (len)
    {
        vector<int> v(len);
        for (int i = 0; i < len; i++)
            cin >> v[i];
        cout << Add(v) << endl;
        cin >> len;
    }

    return 0;
}