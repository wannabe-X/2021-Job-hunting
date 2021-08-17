/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-08-15 18:53:39
 * @LastEditTime: 2021-08-15 19:52:58
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>

using namespace std;

int changeNumber(int num)
{
    long digit = 1;
    int count = 0;
    while (num)
    {
        if ((num & digit) == 0)
            count++;
        if (count == 2)
            break;
        digit <<= 1;
    }

    num = num + digit;

    return num;
}

int main()
{
    int num;
    cin >> num;
    int ans = changeNumber(num);
    cout << ans << endl;

    return 0;
}