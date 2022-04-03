/*
 * @Description: 693. 交替位二进制数
 * @Author: Mr. Lee
 * @Date: 2022-03-28 20:19:33
 * @LastEditTime: 2022-03-28 20:33:25
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool hasAlternatingBits(int n)
{
    int flag = n % 2;
    while (n)
    {
        n /= 2;
        if (flag != n % 2)
            flag = n % 2;
        else
            return false;
    }

    return true;
}

int main(int argc, char *argv[])
{
    int n = 1;
    bool ans = hasAlternatingBits(n);
    cout << boolalpha << ans << endl;

    return 0;
}