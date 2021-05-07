#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string solve(string s, string t)
{
    // write code here
    int i = s.size() - 1, j = t.size() - 1, carry = 0;

    string ans;

    while (i > -1 || j > -1 || carry != 0)
    {
        int x = i > -1 ? s[i--] - '0' : 0, y = j > -1 ? t[j--] - '0' : 0;
        int sum = x + y + carry;
        ans += to_string(sum % 10);
        carry = sum / 10;
    }

    reverse(ans.rbegin(), ans.rend());
    return ans;
}

int main(void)
{
    string s = "0", t = "999";
    string ans = solve(s, t);
    cout << ans << endl;
    return 0;
}