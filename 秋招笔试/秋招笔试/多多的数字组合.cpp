/*
 * @Description: 多多的数字组合
 * @Author: Mr. Lee
 * @Date: 2021-07-25 15:26:43
 * @LastEditTime: 2021-07-25 16:14:07
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>

using namespace std;

int function(int k)
{
    if (k < 10)
        return k;

    int flag = 0, res = 0;
    vector<int> tmp;

    for (int i = 9; i > 0; i--)
    {
        if (k > 0 && k < 10 && k <= i)
        {
            flag = 1;
            tmp.push_back(k);
            break;
        }
        k -= i;
        tmp.push_back(i);
        if (k < 0)
        {
            k += i;
            tmp.pop_back();
        }
    }

    for (int i = tmp.size() - 1; flag && i > -1; i--)
    {
        res = res * 10 + tmp[i];
    }

    return res == 0 ? -1 : res;
}

int main()
{
    int k;
    cin >> k;
    int ans = function(k);
    cout << ans << endl;

    return 0;
}
