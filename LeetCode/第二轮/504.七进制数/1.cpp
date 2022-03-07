/*
 * @Description: 504. 七进制数
 * @Author: Mr. Lee
 * @Date: 2022-03-07 14:59:27
 * @LastEditTime: 2022-03-07 15:09:29
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string convertToBase7(int num)
{
    if (!num)
        return "0";

    int flag = 1;
    if (num < 0)
        flag = -1;

    num = abs(num);
    string res;

    while (num)
    {
        res = to_string(num % 7) + res;
        num /= 7;
    }

    return flag > 0 ? res : '-' + res;
}

int main(int argc, char *argv[])
{
    int num = -1e7;
    string ans = convertToBase7(num);
    cout << ans << endl;

    return 0;
}