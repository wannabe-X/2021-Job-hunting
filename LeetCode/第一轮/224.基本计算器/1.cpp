#include <iostream>
#include <stack>

using namespace std;

int calculate(string s)
{
    s = '+' + s;
    int num = 0, res = 0;
    char sign = '+';
    stack<int> stk;

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (isdigit(c))
            num = num * 10 + (c - '0');

        if (!isdigit(c) && c != ' ' || i == s.size() - 1)
        {
            switch (sign)
            {
                int pre;

            case '+':
                stk.push(num);
                break;

            case '-':
                stk.push(-num);
                break;
            case '*':
                pre = stk.top();
                stk.pop();
                stk.push(pre * num);
                break;
            case '/':
                pre = stk.top();
                stk.pop();
                stk.push(pre / num);
                break;
            }
            sign = c;
            num = 0;
        }
    }

    while (!stk.empty())
    {
        res += stk.top();
        stk.pop();
    }

    return res;
}

int main(void)
{
    string s = "1*2";
    int ans = calculate(s);
    cout << ans << endl;
}