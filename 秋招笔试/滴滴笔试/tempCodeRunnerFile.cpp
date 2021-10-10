/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-10-10 18:57:47
 * @LastEditTime: 2021-10-10 20:02:32
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int func(vector<char> &v)
{
    stack<char> stk;
    stk.push(v[0]);
    int res = 1;

    for (int i = 1; i < v.size(); i++)
    {
        if (!stk.empty() && stk.top() == '0' && v[i] == '1')
        {
            stk.pop();
        }
        else if (!stk.empty() && stk.top() == '2' && v[i] == '3')
        {
            stk.pop();
        }
        else
        {
            stk.push(v[i]);
        }
    }

    if (stk.size() == v.size())
        return 0;

    return (v.size() - stk.size());
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