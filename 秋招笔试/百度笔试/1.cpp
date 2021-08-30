/*
 * @Description: 百度提前批二面(笔试题)
 * @Author: Mr. Lee
 * @Date: 2021-08-30 18:54:22
 * @LastEditTime: 2021-08-31 00:27:01
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int func(int n)
{
    int res = int(sqrt(n));

    return res;
}

int main(void)
{
    int n = 98;
    int ans = func(n);
    cout << ans << endl;

    return 0;
}