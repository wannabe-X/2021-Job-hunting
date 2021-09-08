/*
 * @Description: 剑指 Offer II 085. 生成匹配的括号
 * @Author: Mr. Lee
 * @Date: 2021-09-08 09:08:08
 * @LastEditTime: 2021-09-08 16:58:32
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void boardtrack(vector<string> &res, string tmp, int left, int right)
{
    if (left == 0 && right == 0)
    {
        res.push_back(tmp);
        return;
    }

    if (left > 0)
    {
        tmp += '(';
        boardtrack(res, tmp, left - 1, right);
        tmp.pop_back();
    }

    if (right > left)
    {
        tmp += ')';
        boardtrack(res, tmp, left, right - 1);
        tmp.pop_back();
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> res;
    string tmp;
    boardtrack(res, tmp, n, n);

    return res;
}

int main(void)
{
    int n = 3;
    vector<string> ans = generateParenthesis(n);
    for (auto &x : ans)
    {
        cout << x << endl;
    }

    return 0;
}