#include <iostream>
#include <stack>
#include <string>

using namespace std;

int calculate(string s)
{
    char chars[] = "()";

    while (s.find('(') != -1)
    {
        s.erase(s.find('('), 1);
    }

    while (s.find(')') != -1)
    {
        s.erase(s.find(')'), 1);
    }

    // for (int i = 0; i < s.size(); i++)
    //     cout << s[i] << endl;

    int num = 0, res = 0, sign = 1;
    stack<int> stk;

    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
            num = num * 10 + (s[i] - '0');
        else if (s[i] == '+' || s[i] == '-')
        {
            res += num * sign;
            num = 0;
            sign = (s[i] == '+') ? 1 : -1;
        }
    }

    res += num * sign;
    return res;
}

int main(void)
{
    string s = "(1+(4+5+2)-3)+(6+8)";
    int ans = calculate(s);
    cout << ans << endl;
}