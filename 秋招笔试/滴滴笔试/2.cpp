/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-10-10 18:57:47
 * @LastEditTime: 2021-10-10 20:58:42
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool check(vector<char> &v, int l, int r)
{
    stack<char> stk;

    for (int i = l; i < r; i++)
    {
        if (!stk.empty() && ((stk.top() == '0' && v[i] == '1') || (stk.top() == '2' && v[i] == '3')))
        {
            stk.pop();
        }
        else
        {
            stk.push(v[i]);
        }
    }

    return stk.empty();
}

int func(vector<char> &v)
{
    int res = -1;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j <= v.size(); j++)
        {
            if (j - i < res)
                continue;
            if (check(v, i, j))
                res = max(res, j - i);
        }
    }

    return res;
}

int main(void)
{
    int n;
    cin >> n;
    vector<char> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int ans = func(v);
    cout << ans << endl;

    return 0;
}