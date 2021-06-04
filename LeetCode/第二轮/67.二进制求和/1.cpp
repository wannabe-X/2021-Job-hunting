#include <iostream>
#include <algorithm>

using namespace std;

string addBinary(string a, string b)
{
    string ans;
    int carry = 0;
    int a1 = 0, b1 = 0;
    int m = a.size() - 1, n = b.size() - 1;

    while (m > -1 || n > -1)
    {
        a1 = (m > -1) ? a[m] - '0' : 0;
        b1 = (n > -1) ? b[n] - '0' : 0;

        int sum = a1 + b1 + carry;
        ans += to_string(sum % 2);
        // 处理进位
        carry = (sum < 2) ? 0 : 1;

        m--;
        n--;
    }

    // 进位判断,添加
    ans = carry == 1 ? ans + to_string(carry) : ans;
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string a = "1000", b = "101";
    string ans = addBinary(a, b);
    cout << ans << endl;
    return 0;
}