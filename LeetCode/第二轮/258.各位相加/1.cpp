/*
 * @Description: 258. 各位相加
 * @Author: Mr. Lee
 * @Date: 2022-03-03 10:12:00
 * @LastEditTime: 2022-03-03 10:13:02
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int addDigits(int num)
{
    if (!num)
        return 0;
    return num % 9 == 0 ? 9 : num % 9;
}

int main(int argc, char *argv[])
{
    int num = 38;
    int ans = addDigits(num);
    cout << ans << endl;

    return 0;
}