/*
 * @Description: 415. 字符串相加
 * @Author: Mr. Lee
 * @Date: 2021-09-16 15:08:44
 * @LastEditTime: 2021-09-16 15:21:01
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string addStrings(string num1, string num2)
{
    string res;
    int n1 = num1.size() - 1, n2 = num2.size() - 1;
    int digit = 0;
    while (n1 > -1 || n2 > -1)
    {
        int t1 = n1 > -1 ? num1[n1--] - '0' : 0;
        int t2 = n2 > -1 ? num2[n2--] - '0' : 0;
        int tmpSum = (t1 + t2 + digit);

        res += to_string(tmpSum % 10);
        digit = tmpSum / 10;
    }
    if (digit)
        res += to_string(digit);

    if (res.empty())
        return "0";

    reverse(res.begin(), res.end());

    return res;
}

int main(void)
{
    string num1 = "1", num2 = "9";
    string ans = addStrings(num1, num2);
    cout << ans << endl;

    return 0;
}