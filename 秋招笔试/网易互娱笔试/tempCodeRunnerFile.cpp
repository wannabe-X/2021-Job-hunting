/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-17 19:37:39
 * @LastEditTime: 2021-09-17 21:46:13
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int func(vector<int> &v, vector<int> &v1)
{
    int res = 0;
    int right, left;
    int pivot = v1[v[1]];

    for (int i = v[1] + 1; i < v[0]; i++)
    {
        if (v1[i] >= pivot)
        {
            right = i;
            break;
        }
    }

    for (int i = v[1] - 1; i > -1; i--)
    {
        if (v1[i] >= pivot)
        {
            left = i;
            break;
        }
    }

    for (int i = right; i < v[0] - 1; i++)
    {
        if (v1[i] > v1[i + 1])
            res++;
    }

    for (int i = left; i > 0; i--)
    {
        if (v1[i] > v1[i - 1])
            res++;
    }

    return res;
}

int main(void)
{
    int N;
    cin >> N;
    vector<int> v(2);
    vector<int> v1(N);
    while (N--)
    {
        for (int i = 0; i < 2; i++)
            cin >> v[i];
        for (int i = 0; i < v[0]; i++)
            cin >> v1[i];

        int ans = func(v, v1);
        v.clear(), v1.clear();
        cout << ans << endl;
    }

    return 0;
}