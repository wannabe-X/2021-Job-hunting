#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string solve(string s, string t)
{
    // write code here
    int i = s.size() - 1, j = t.size() - 1, carry = 0;

    string ans;

    while (i > -1 && j > -1)
    {
        int sum = (s[i] - '0') + (t[j] - '0') + carry;
        ans += to_string(sum % 10);
        carry = sum / 10;
        i--;
        j--;
    }

    if (i >= 0)
    {
        for (; i > -1; i--)
        {
            int sum = (s[i] - '0') + carry;
            ans += to_string(sum % 10);
            carry = sum / 10;
        }
    }
    else
    {
        for (; j > -1; j--)
        {
            int sum = (t[j] - '0') + carry;
            ans += to_string(sum % 10);
            carry = sum / 10;
        }
    }

    if (carry > 0)
        ans += to_string(carry);
    reverse(ans.rbegin(), ans.rend());

    return ans;
}

int main(void)
{
    string s = "0", t = "0";
    string ans = solve(s, t);
    cout << ans << endl;
    return 0;
}