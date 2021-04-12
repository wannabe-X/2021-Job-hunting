#include <iostream>
#include <stack>
using namespace std;

char leftOf(char c)
{
    if (c == ')')
        return '(';
    if (c == ']')
        return '[';
    return '{';
}

bool isValid(string s)
{
    stack<int> left;
    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
            left.push(c);
        else
        {
            if (!left.empty() && leftOf(c) == left.top())
                left.pop();
            else
                return false;
        }
    }
    return left.empty();
}

int main(void)
{
    string s = "[(])";
    bool ans = isValid(s);
    cout << boolalpha << ans << endl;
}