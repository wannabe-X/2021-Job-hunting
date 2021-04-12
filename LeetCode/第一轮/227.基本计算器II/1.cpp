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
            // ��������ǰ��ķ���λ���
            res *= stk.top();
            stk.pop();
            // ���������������֮ǰ�ļ��������
            res += stk.top();
            stk.pop();
        }
    }
    // (1+2) + 3 Ҫ�Ѻ����䵥�����ּ���
    res += sign * num;
    return res;
}



int main(void)
{
    string s = "(1+(4+5+2)-3)+(6+8)";
    int ans = calculate(s);
    cout << ans << endl;
}