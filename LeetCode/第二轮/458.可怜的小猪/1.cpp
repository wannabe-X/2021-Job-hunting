/*
 * @Description: 458. 可怜的小猪
 * @Author: Mr. Lee
 * @Date: 2021-11-25 00:12:05
 * @LastEditTime: 2021-11-25 15:26:34
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int poorPigs(int buckets, int minutesToDie, int minutesToTest)
{
    int base = minutesToTest / minutesToDie + 1;
    return ceil(log10(buckets) / log10(base));
}

int main(int argc, char *argv[])
{
    int buckets = 1000, minutesToDie = 15, minutesToTest = 60;
    int ans = poorPigs(buckets, minutesToDie, minutesToTest);
    cout << ans << endl;

    return 0;
}