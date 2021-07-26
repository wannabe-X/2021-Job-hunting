/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-07-26 22:49:28
 * @LastEditTime: 2021-07-26 23:06:27
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int tmp, sum = 0;
    while (cin >> tmp)
    {
        sum += tmp;
        if (cin.get() == '\n')
        {
            cout << sum << endl;
            sum = 0;
        }
    }
    return 0;
}