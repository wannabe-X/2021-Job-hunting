/*
 * @Description: 65. 有效数字。使用正则匹配
 * @Author: Mr. Lee
 * @Date: 2021-06-17 09:41:00
 * @LastEditTime: 2021-06-17 15:08:24
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <regex>

using namespace std;

const regex pattern("\\s*([+-]?(?:\\d+\\.?\\d*|\\.\\d+)(?:[Ee][+-]?\\d+)?)\\s*");

bool isNumber(string str)
{
    return regex_match(str, pattern);
}

int main()
{
    string s = "0";
    bool ans = isNumber(s);
    cout << boolalpha << ans << endl;

    return 0;
}
