#include <iostream>
#include <stack>

using namespace std;

int calculate(string s)
{
    int num = 0, res = 0, sign = 1;
    stack<int> stk;
    for (const char &c : s)
    {
        if (isdigit(c))
        {
            num = num * 10 + (c - '0');
        }

        else if (c == '+' || c == '-')
        {
            res += sign * num;
            num = 0;
            sign = (c == '+') ? 1 : -1;
        }

        else if (c == '(')
        {
            stk.push(res);
            stk.push(sign);
            res = 0;
            sign = 1;
        }
        else if (c == ')')
        {
            res += sign * num;
            num = 0;
            // 与左括号前面的符号位相乘
            res *= stk.top();
            stk.pop();
            // 括号里面的内容与之前的计算结果相加
            res += stk.top();
            stk.pop();
        }
    }
    // (1+2) + 3 要把后面落单的数字加上
    res += sign * num;
    return res;
}



int main(void)
{
    string s = "(1+(4+5+2)-3)+(6+8)";
    int ans = calculate(s);
    cout << ans << endl;
}