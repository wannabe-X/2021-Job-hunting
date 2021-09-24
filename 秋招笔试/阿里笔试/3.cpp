/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-24 18:57:19
 * @LastEditTime: 2021-09-24 22:06:16
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
using namespace std;

int func(unsigned int n)
{
    vector<int> m;
    for (int i = 31; i >= 0; i--)
    {
        m.push_back(((n >> i) & 1)); //与1做位操作，前面位数均为0
    }

    int idx = m.size();
    for (int i = 0; i < m.size(); i++)
    {
        if (m[i] == 1)
        {
            idx = i;
            break;
        }
    }

    return 31 - idx;
}

int main(void)
{
    unsigned int num = 999999;
    int ans = func(num);
    cout << ans << endl;

    return 0;
}