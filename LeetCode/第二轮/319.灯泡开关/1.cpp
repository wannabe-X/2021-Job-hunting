/*
 * @Description: 319. 灯泡开关
 * @Author: Mr. Lee
 * @Date: 2021-11-15 14:50:16
 * @LastEditTime: 2021-11-15 14:53:04
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int bulbSwitch(int n)
{
    return int(sqrt(n));
}

int main(int argc, char **argv)
{
    int n = 3;
    int ans = bulbSwitch(n);
    cout << ans << endl;
    
    return 0;
}