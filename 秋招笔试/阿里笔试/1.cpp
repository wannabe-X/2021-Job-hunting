/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-24 18:57:12
 * @LastEditTime: 2021-09-24 19:12:44
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int func(int N, string str)
{
    int res = 0, tmp1 = 0, tmp2 = 0;
    if (str[0] == 'B')
        tmp1++;
    if (str[0] == 'R')
        tmp2++;

    for (int i = 1; i < N; i++)
    {
        if (str[i] == str[i - 1])
            continue;
        if (str[i] == 'B')
            tmp1++;
        if (str[i] == 'R')
            tmp2++;
    }

    res = (tmp1 < tmp2) ? tmp1 + 1 : tmp2 + 1;

    return res;
}

int main(void)
{
    int N;
    cin >> N;
    string str;
    cin >> str;
    int ans = func(N, str);
    cout << ans;

    return 0;
}