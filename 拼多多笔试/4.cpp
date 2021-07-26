/*
 * @Description: 无限状态集合
 * @Author: Mr. Lee
 * @Date: 2021-07-25 18:51:59
 * @LastEditTime: 2021-07-26 16:37:41
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

int func(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        if (a[1] == 0 || a[2] == 0)
        {
            return 0;
            continue;
        }
        if (a[0] == a[3] || (a[3] - a[0]) % a[1] == 0 ||
            ((a[3] - a[0]) / a[1]) % a[2] == 0)
            return 1;
        else
            return 0;
    }

    return 0;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(4);

    while (n--)
    {
        for(int i = 0; i < 4; i++)
            cin >> a[i];
        cout << func(a) << endl;
    }

    return 0;
}
