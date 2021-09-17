/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-17 17:57:23
 * @LastEditTime: 2021-09-17 17:59:29
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <stack>
#include <set>
using namespace std;
int main()
{
    int n;
    cin >> n;
    stack<int> stk;
    set<stack<int>> ans;
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        if (a == "push")
        {
            int b;
            cin >> b;
            stk.push(b);
            ans.insert(stk);
        }
        if (a == "pop")
        {
            if (stk.size() == 0)
            {
                continue;
            }
            stk.pop();
            if (stk.size() > 0)
            {
                ans.insert(stk);
            }
        }
    }
    cout << ans.size() << endl;
    return 0;
}