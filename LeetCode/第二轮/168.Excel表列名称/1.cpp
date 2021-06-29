/*
 * @Description: 168. Excel表列名称
 * @Author: Mr. Lee
 * @Date: 2021-06-29 09:30:49
 * @LastEditTime: 2021-06-29 10:30:12
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <algorithm>

using namespace std;

string convertToTitle(int columnNumber)
{
    string ans;
    while (columnNumber > 0)
    {
        int a0 = (columnNumber - 1) % 26 + 1;
        ans += a0 - 1 + 'A';
        columnNumber = (columnNumber - a0) / 26;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int columnNumber = 701;
    string ans = convertToTitle(columnNumber);
    cout << ans << endl;

    return 0;
}
