/*
 * @Description: 剑指 Offer II 002. 二进制加法
 * @Author: Mr. Lee
 * @Date: 2021-08-12 00:19:01
 * @LastEditTime: 2021-08-12 00:37:02
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string addBinary(string a, string b)
{
    string ans = "";
    int carry = 0;

    int m = a.size() - 1, n = b.size() - 1;

    while (m > -1 || n > -1)
    {
        int tmpa = m > -1 ? (a[m--] - '0') : 0,
            tmpb = n > -1 ? (b[n--] - '0') : 0;
        int tsum = tmpa + tmpb + carry;
        ans += (tsum % 2 + '0');
        carry = tsum >= 2 ? 1 : 0;
    }

    if (carry == 1)
        ans += '1';

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    string a, b;
    cin >> a >> b;
    string ans = addBinary(a, b);
    cout << ans << endl;

    return 0;
}
