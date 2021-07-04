/*
 * @Description: 栈的压入、弹出序列
 * @Author: Mr. Lee
 * @Date: 2021-07-04 19:16:59
 * @LastEditTime: 2021-07-05 00:01:33
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool IsPopOrder(vector<int> pushV, vector<int> popV)
{
    stack<int> stk;
    int idx = 0;
    for (int num : pushV)
    {
        stk.push(num);
        while ((idx < pushV.size()) && (!stk.empty()) && (stk.top() == popV[idx]))
        {
            stk.pop();
            idx++;
        }
    }

    return stk.empty();
}

int main()
{
    vector<int> pushV = {1, 2, 3, 4, 5}, popV = {1, 2, 3, 4, 5};
    bool ans = IsPopOrder(pushV, popV);
    cout << boolalpha << ans << endl;

    return 0;
}
