#include <iostream>
#include <vector>

using namespace std;

string solve(string s, string t)
{
    // write code here
    int i = s.size() - 1, j = t.size() - 1, carry = 0;
    vector<int> res(s.size() + t.size(), 0);
    int digit = s.size() + t.size() - 1;
    string ans;

    while (i > -1 && j > -1)
    {
        int sum = (s[i] - '0') + (t[j] - '0') + carry;
        res[digit] += sum % 10;
        carry = sum / 10;
        digit--;
        i--;
        j--;
    }

    if (i >= 0)
    {
        for (; i > -1; i--)
        {
            int sum = (s[i] - '0') + carry;
            res[digit] += sum % 10;
            carry = sum / 10;
            digit--;
        }
    }
    else
    {
        for (; j > -1; j--)
        {
            int sum = (t[j] - '0') + carry;
            res[digit] += sum % 10;
            carry = sum / 10;
            digit--;
        }
    }

    res[digit] = carry;

    for (i = 0; i < res.size() && res[i] == 0; i++)
        ;
    for (; i < res.size(); ans += to_string(res[i]), i++)
        ;
    return ans;
}

int main(void)
{
    string s = "1", t = "9";
    string ans = solve(s, t);
    cout << ans << endl;
    return 0;
}