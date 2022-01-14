/*
 * @Description: 1614. 括号的最大嵌套深度
 * @Author: Mr. Lee
 * @Date: 2022-01-07 17:28:14
 * @LastEditTime: 2022-01-07 17:34:17
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int maxDepth(string s)
{
    int res = 0, depth = 0;
    for (char c : s)
    {
        if (c == '(')
            depth++;
        else if (c == ')')
            depth--;
        res = max(res, depth);
    }

    return res;
}

int main(int argc, char *argv[])
{
    string s = "1+(2*3)/(2-1)";
    int ans = maxDepth(s);
    cout << ans << endl;

    return 0;
}