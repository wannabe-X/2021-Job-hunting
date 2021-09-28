/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-28 09:57:21
 * @LastEditTime: 2021-09-28 10:44:39
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> func(string a, string b)
{
    int len_a = a.size(), len_b = b.size();
    if (len_a < 1 || len_b < 1)
        return {0, 0};

    if (len_b % len_a)
    {
        return {0, 0};
    }

    for (int i = 0; i < len_b; i += len_a)
    {
        if (b.substr(i, len_a) != a)
            return {0, 0};
    }

    return {1, len_b / len_a};
}

int main(void)
{
    string a, b;
    cin >> a >> b;
    vector<int> ans = func(a, b);
    if (ans[0] == 1)
        cout << "a字符串可以重复" << ans[1] << "次得到b字符串" << endl;
    else
        cout << "a字符串不可以重复若干次得到b字符串" << endl;
    
    return 0;
}