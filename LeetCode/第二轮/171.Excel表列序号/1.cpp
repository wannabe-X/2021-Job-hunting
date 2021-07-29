/*
 * @Description: 171. Excel表列序号
 * @Author: Mr. Lee
 * @Date: 2021-07-30 00:02:03
 * @LastEditTime: 2021-07-30 00:15:29
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

int titleToNumber(string columnTitle)
{
    int result = 0, carry = 1;
    for (auto &x : columnTitle)
    {
        result = result * carry + (x - 'A' + 1);
        carry *= 26;
    }

    return result;
}

int main()
{
    string columnTitle = "ZY";
    int ans = titleToNumber(columnTitle);
    cout << ans << endl;

    return 0;
}
