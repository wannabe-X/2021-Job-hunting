/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-08-21 17:41:01
 * @LastEditTime: 2021-08-21 17:53:06
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>

using namespace std;

int ysf_function(int n, int m)
{
    int x = 0; // f(1,m) = 0

    for (int i = 2; i <= n; i++)
    {
        x = (x + m) % i;
    }

    return x + 1;
}

int main()
{
    int n = 5, m = 3;
    int ans = ysf_function(n, m);
    cout << ans << endl;

    return 0;
}