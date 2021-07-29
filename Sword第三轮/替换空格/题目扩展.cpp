/*
 * @Description: 题目扩展问题，合并两个有序数组
 * @Author: Mr. Lee
 * @Date: 2021-07-26 17:46:03
 * @LastEditTime: 2021-07-28 14:15:20
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeTwoVectors(vector<int> a, vector<int> b)
{
    int m = a.size(), n = b.size(), k = m + n;
    a.resize(k);

    m -= 1;
    n -= 1;

    while (m > -1 && n > -1)
    {
        a[--k] = a[m] < b[n] ? b[n--] : a[m--];
    }

    if (n > 0)
    {
        for (int i = n; i > -1; i--)
        {
            a[k--] = b[i];
        }
    }
    else if (m > 0)
    {
        for (int i = m; i > -1; i--)
        {
            a[--k] = a[i];
        }
    }

    return a;
}

int main()
{
    // vector<int> a = {1, 2, 3, 6, 7, 11};
    // vector<int> b = {4, 5, 9};

    vector<int> a, b, *tmp;
    tmp = &a;
    int idx = 0;
    int num;

    while (idx < 2 && cin >> num)
    {
        (*tmp).push_back(num);
        if (cin.get() == '\n')
        {
            idx++; 
            tmp = &b;
        }
    }

    vector<int> ans = mergeTwoVectors(a, b);
    for (auto &x : ans)
        cout << x << " ";

    return 0;
}