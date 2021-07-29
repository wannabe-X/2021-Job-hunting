/*
 * @Description: 打印1到最大的n位数
 * @Author: Mr. Lee
 * @Date: 2021-07-29 17:38:43
 * @LastEditTime: 2021-07-29 22:55:47
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

void PrintNumber(vector<char> &res)
{
    int isBegin0 = 1;
    for (int i = 0; i < res.size(); i++)
    {
        if (isBegin0 && res[i] != '0')
            isBegin0 = 0;
        if (isBegin0 == 0)
        {
            cout << res[i];
        }
    }

    if (isBegin0 == 0)
        cout << endl;
}

void Print1ToMaxOfNDigitsRecursively(vector<char> &res, int idx)
{
    if (idx == res.size() - 1)
    {
        PrintNumber(res);
        return;
    }

    for (int i = 0; i < 10; i++)
    {
        res[idx + 1] = i + '0';
        Print1ToMaxOfNDigitsRecursively(res, idx + 1);
    }
}

void Print1ToMaxOfNDigits(int n)
{
    if (n <= 0)
        return;
    vector<char> res(n);

    for (int i = 0; i < 10; i++)
    {
        res[0] = '0' + i;
        Print1ToMaxOfNDigitsRecursively(res, 0);
    }
}

int main()
{
    int n = 1;
    Print1ToMaxOfNDigits(n);
    return 0;
}
