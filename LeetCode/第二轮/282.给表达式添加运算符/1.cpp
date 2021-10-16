/*
 * @Description: 282. 给表达式添加运算符
 * @Author: Mr. Lee
 * @Date: 2021-10-16 00:20:26
 * @LastEditTime: 2021-10-16 11:35:51
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string s;
int n, t;
vector<string> res;

void dfs(int idx, long prev, long cur, string ss)
{
    if (idx == n)
    {
        if (cur == t)
            res.push_back(ss);
        return;
    }

    for (int i = idx; i < n; i++)
    {
        if (i != idx && s[idx] == '0')
            break;

        long next = stol(s.substr(idx, i + 1 - idx));
        if (idx == 0)
            dfs(i + 1, next, next, "" + to_string(next));
        else
        {
            dfs(i + 1, next, cur + next, ss + '+' + to_string(next));
            dfs(i + 1, -next, cur - next, ss + '-' + to_string(next));

            long tmp = prev * next;
            dfs(i + 1, tmp, cur - prev + tmp, ss + '*' + to_string(next));
        }
    }
}

vector<string> addOperators(string num, int target)
{
    s = num;
    n = s.size();
    t = target;
    dfs(0, 0, 0, "");
    return res;
}

int main(void)
{
    string num = "10023";
    int target = 6;
    vector<string> ans = addOperators(num, target);
    for (string &str : ans)
        cout << str << endl;

    return 0;
}
