/*
 * @Description: 171. Excel表列序号
 * @Author: Mr. Lee
 * @Date: 2021-07-30 00:02:03
 * @LastEditTime: 2021-07-30 00:18:23
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

int titleToNumber(string columnTitle)
{
    int result = 0;
    for (auto &x : columnTitle)
        result = result * 26 + (x - 'A' + 1);

    return result;
}

int main()
{
    string columnTitle = "ZY";
    int ans = titleToNumber(columnTitle);
    cout << ans << endl;

    return 0;
}
